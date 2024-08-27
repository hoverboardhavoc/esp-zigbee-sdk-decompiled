/*
 * Last changed at upstream commit eec5098a388a0960da2662a0145e34c21f0838a0
 * https://github.com/espressif/esp-zigbee-sdk/commit/eec5098a388a0960da2662a0145e34c21f0838a0
 * Upstream date: 2024-08-27 08:46:30 +0000
 * Upstream subject: esp-zigbee-lib:(6bd34178)
 * Source: libesp_zb_api_zczr.debug -> esp_zigbee_ota.o -> get_ota_upgrade_server_variables
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Control flow encountered bad instruction data */

undefined4 get_ota_upgrade_server_variables(void)

{
  int iVar1;
  
  iVar1 = zb_zcl_get_attr_desc_a(0x19,1,0xfff0);
  if (iVar1 != 0) {
    return *(undefined4 *)(iVar1 + 6);
  }
  zb_assert("/builds/thread_zigbee/esp-zboss/components/esp_zb_sdk/src/esp_zigbee_ota.c",0x38);
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}

