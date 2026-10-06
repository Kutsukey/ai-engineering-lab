import pandas as pd
from sklearn.datasets import load_breast_cancer

X, y = load_breast_cancer(as_frame=True, return_X_y=True)

print(X.shape)
print(X.head())
print(y.value_counts())
print(
    "NA:", X.isna().sum().sum()
)  # ilk sum her sütun için kaç eksik var, ikinci sum o sayıların toplamı

from sklearn.model_selection import train_test_split

X_train, X_test, y_train, y_test = train_test_split(
    X, y, test_size=0.2, random_state=42, stratify=y
)
print(X_train.shape, X_test.shape)

from sklearn.dummy import DummyClassifier
from sklearn.model_selection import cross_val_score

dummy = DummyClassifier(strategy="most_frequent")
scores = cross_val_score(dummy, X_train, y_train, cv=5)
print(f"baseline: {scores.mean():.4f}")  # 0.6264

from sklearn.pipeline import make_pipeline
from sklearn.preprocessing import StandardScaler
from sklearn.linear_model import LogisticRegression
from sklearn.tree import DecisionTreeClassifier
from sklearn.ensemble import RandomForestClassifier

models = {
    "logreg": make_pipeline(StandardScaler(), LogisticRegression(max_iter=1000)),
    "tree": DecisionTreeClassifier(random_state=42),
    "forest": RandomForestClassifier(random_state=42),
}

for name, model in models.items():
    scores = cross_val_score(model, X_train, y_train, cv=5)
    print(f"{name:7s} mean={scores.mean():.3f} std={scores.std():.3f}")
    # logreg  mean=0.985 std=0.009
    # tree    mean=0.943 std=0.019
    # forest  mean=0.960 std=0.005

for depth in range(1, 11):
    tree = DecisionTreeClassifier(max_depth=depth, random_state=42)
    tree.fit(X_train, y_train)
    train_acc = tree.score(X_train, y_train)
    cv_acc = cross_val_score(tree, X_train, y_train, cv=5).mean()
    # print(f"depth={depth:2d} train={train_acc:.3f} cv={cv_acc:.5f}") # 6 dan sonra cv_acc düşüyor (overfit)

from sklearn.metrics import classification_report, confusion_matrix

best = models["logreg"]  # cv = 0.985
best.fit(X_train, y_train)
y_pred = best.predict(X_test)

print(confusion_matrix(y_test, y_pred))
print(classification_report(y_test, y_pred, target_names=["malignant", "benign"]))
