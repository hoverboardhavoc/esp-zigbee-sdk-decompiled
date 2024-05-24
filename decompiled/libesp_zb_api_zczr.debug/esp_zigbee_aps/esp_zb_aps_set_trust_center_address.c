/*
 * Last changed at upstream commit 9b2a25d84666d8bc8515f84abcf92271524d2896
 * https://github.com/espressif/esp-zigbee-sdk/commit/9b2a25d84666d8bc8515f84abcf92271524d2896
 * Upstream date: 2024-05-24 08:27:18 +0000
 * Upstream subject: esp-zigbee-lib:(73447d7e)
 * Source: libesp_zb_api_zczr.debug -> esp_zigbee_aps.o -> esp_zb_aps_set_trust_center_address
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 esp_zb_aps_set_trust_center_address(undefined1 *param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = zb_zdo_joined();
  if (iVar1 == 0) {
    DAT_00011680 = *param_1;
    DAT_00011681 = param_1[1];
    DAT_00011682 = param_1[2];
    DAT_00011683 = param_1[3];
    DAT_00011684 = param_1[4];
    DAT_00011685 = param_1[5];
    DAT_00011686 = param_1[6];
    DAT_00011687 = param_1[7];
    uVar2 = 0;
  }
  else {
    uVar2 = 0x103;
  }
  return uVar2;
}

