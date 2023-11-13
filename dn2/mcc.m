(* ::Package:: *)

MonteCarlo[n_Integer]:=Module[{tocke,skupnoTock},tocke=0;
skupnoTock=n;

Do[{x,y}=RandomReal[{-1,1},2];
If[x^2+y^2<=1,tocke++],{skupnoTock}];

4*tocke/skupnoTock]
