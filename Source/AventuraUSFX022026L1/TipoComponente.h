#pragma once

#include "CoreMinimal.h"
#include "TipoComponente.generated.h"

UENUM(BlueprintType)
enum class ETipoComponente : uint8
{
    ESCUDO      UMETA(DisplayName = "Escudo"),
    MOTOR       UMETA(DisplayName = "Motor"),
    ARMA        UMETA(DisplayName = "Arma"),
    NUCLEO      UMETA(DisplayName = "Nucleo"),
    SENSOR      UMETA(DisplayName = "Sensor")
};