/*
 * Last changed at upstream commit 438301125bdfa70150622d905094f79315456774
 * https://github.com/espressif/esp-zigbee-sdk/commit/438301125bdfa70150622d905094f79315456774
 * Upstream date: 2024-04-26 19:22:10 +0800
 * Upstream subject: esp-zigbee-sdk: release/v1.3.0(a824e1a1)
 * Source: libesp_zb_api_zczr -> esp_zigbee_core.o -> esp_zb_factory_reset
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 esp_zb_factory_reset(void)

{
  byte *pbVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 extraout_a1;
  
  zb_zcl_init_reporting_info();
  zb_zcl_reset_reporting_ctx();
  zb_bdb_reset_via_local_action(0);
  zb_nvram_erase();
                    /* WARNING: Read-only address (ram,0x00011c41) is written */
  uRam00011c41 = 0xcc;
  iVar2 = esp_restart();
  iVar3 = zb_zcl_get_ctx();
  pbVar1 = *(byte **)(iVar3 + 4);
  uVar4 = 0xffffffff;
  if (pbVar1 != (byte *)0x0) {
    uVar4 = 0;
    for (iVar3 = 0; iVar3 < (int)(uint)*pbVar1; iVar3 = iVar3 + 1) {
      uVar4 = reset_endpoint_to_factory_default
                        (*(undefined4 *)(*(int *)(pbVar1 + 1) + iVar3 * 4),iVar2,extraout_a1);
    }
    if (iVar2 != 0) {
      zb_zcl_reset_reporting_ctx();
    }
  }
  return uVar4;
}

