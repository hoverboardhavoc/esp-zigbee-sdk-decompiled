/*
 * Last changed at upstream commit 790bc8d6ece1bf5f739debaa4aa4af508982070a
 * https://github.com/espressif/esp-zigbee-sdk/commit/790bc8d6ece1bf5f739debaa4aa4af508982070a
 * Upstream date: 2023-12-21 19:52:25 +0800
 * Upstream subject: esp-zigbee-sdk: release/v1.0.7(bdde218a)
 * Source: libesp_zb_cli_command -> zb_esp_cli_cmd_zcl.o -> zb_cli_zcl_cmd_cb
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int zb_cli_zcl_cmd_cb(int param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  arg_parse(&zcl_args);
  if (param_1 < 3) {
    uVar2 = esp_log_timestamp();
    esp_log_write(1,0x10000,&_LC1,uVar2,0x10000);
    iVar1 = 1;
  }
  else {
    if (*(int *)(zcl_args + 0x34) != 0) {
      cmd_zb_general_cmd(param_1 + -2,param_2 + 8);
    }
    if (*(int *)(DAT_000103cc + 0x34) != 0) {
      cmd_zb_attr(param_1 + -2,param_2 + 8);
    }
    if (*(int *)(DAT_000103d0 + 0x34) != 0) {
      cmd_zb_subscribe(param_1 + -2,param_2 + 8);
    }
    iVar1 = *(int *)(DAT_000103d4 + 0x34);
    if (iVar1 != 0) {
      cmd_zb_ping(param_1 + -2,param_2 + 8);
      iVar1 = 0;
    }
  }
  return iVar1;
}

