/*
 * Last changed at upstream commit a67793c7af0a02d983345915fecc5d8fce7a0945
 * https://github.com/espressif/esp-zigbee-sdk/commit/a67793c7af0a02d983345915fecc5d8fce7a0945
 * Upstream date: 2024-02-22 20:57:09 +0800
 * Upstream subject: esp-zigbee-sdk: release/v1.1.2(af7a8c4d)
 * Source: libesp_zb_api_zczr -> esp_zigbee_core.o -> find_device_endpoint
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

byte * find_device_endpoint(uint param_1)

{
  uint uVar1;
  int iVar2;
  byte *pbVar3;
  byte *pbVar4;
  
  uVar1 = 0;
  do {
    if (1 < uVar1) {
      return (byte *)0x0;
    }
    iVar2 = zb_zcl_get_ctx();
    if (*(int *)(iVar2 + uVar1 * 4 + 8) != 0) {
      iVar2 = zb_zcl_get_ctx();
      pbVar4 = *(byte **)(iVar2 + uVar1 * 4 + 8);
      for (iVar2 = 0; iVar2 < (int)(uint)*pbVar4; iVar2 = iVar2 + 1) {
        pbVar3 = *(byte **)(*(int *)(pbVar4 + 1) + iVar2 * 4);
        if (*pbVar3 == param_1) {
          return pbVar3;
        }
      }
    }
    uVar1 = uVar1 + 1;
  } while( true );
}

