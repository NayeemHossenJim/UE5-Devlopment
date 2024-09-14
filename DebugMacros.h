#pragma once

#define DRAW_SPEHERE_SingleTime(Location) if(GetWorld()) DrawDebugSphere(GetWorld(), Location, 25.f, 24.f, FColor::Cyan, false, -1.f, 1.f);
#define DRAW_LINE_SingleTime(Loaction,EndLocation) if(GetWorld()) DrawDebugLine(GetWorld(), Location, EndLocation, FColor::Black, false, -1.f, 1.f);
#define DRAW_POINT_SingleTime(EndLocation) if(GetWorld()) DrawDebugPoint(GetWorld(), EndLocation, 15.f, FColor::Green, false, -1.f, 1.f);