# ConvertHexVolToTetVol

Convert a HexVolField into a TetVolField.

**Detailed Description**

Given a Hex field (or anything that supports the same interface) as input, produce a TetVol as output -- each Hex element gets split into 5 Tets. In order to produce consistent splits across faces, we alternate between two different templates for how to do the split. Currently HexVolMesh, StructHexVolMesh, and LatVolMesh fields can be converted into TetVolMeshes.
