# CalculateSignedDistanceToField

Creates a field with distances to a closed volume; inside the closed volume the field is positive and negative outside.

**Detailed Description**

This function needs an object field that is a volume or a closed surface. When inside the object the distance field is positive, when outside it is negative. The module will fail for not close surfaces as one cannot define inside and outside. Similarly this function will not work for objects that are lines or points. Use the [CalculateDistanceToField](CalculateDistanceToField.md) module for these objects.
