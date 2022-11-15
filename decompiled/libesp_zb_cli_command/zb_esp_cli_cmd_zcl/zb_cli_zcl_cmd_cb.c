/*
 * Last changed at upstream commit 55d58f0243c7dca5c0887a2b065178dacc2d00be
 * https://github.com/espressif/esp-zigbee-sdk/commit/55d58f0243c7dca5c0887a2b065178dacc2d00be
 * Upstream date: 2022-11-15 14:25:21 +0800
 * Upstream subject: cli: Add cli example
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
    esp_log_write(1,0x10000,&_LC4,uVar2,0x10000);
    iVar1 = 1;
  }
  else {
    if (*(int *)(zcl_args + 0x34) != 0) {
      cmd_zb_general_cmd(param_1 + -2,param_2 + 8);
    }
    if (*(int *)(DAT_000103b8 + 0x34) != 0) {
      cmd_zb_attr(param_1 + -2,param_2 + 8);
    }
    if (*(int *)(DAT_000103bc + 0x34) != 0) {
      cmd_zb_subscribe(param_1 + -2,param_2 + 8);
    }
    iVar1 = *(int *)(DAT_000103c0 + 0x34);
    if (iVar1 != 0) {
      cmd_zb_ping(param_1 + -2,param_2 + 8);
      iVar1 = 0;
    }
  }
  return iVar1;
}

