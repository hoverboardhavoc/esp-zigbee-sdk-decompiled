/*
 * Last changed at upstream commit 2e2b779251f791b76c34cc582bf68595de9ac19b
 * https://github.com/espressif/esp-zigbee-sdk/commit/2e2b779251f791b76c34cc582bf68595de9ac19b
 * Upstream date: 2024-02-02 22:15:44 +0800
 * Upstream subject: feat(spinel): support zigbee radio spinel
 * Source: libesp_zb_cli_command -> zb_esp_cli_cmd_zdo.o -> zb_cli_zdo_cmd_cb
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int zb_cli_zdo_cmd_cb(int param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  arg_parse(&zdo_args);
  if (param_1 < 2) {
    uVar2 = esp_log_timestamp();
    esp_log_write(1,&_LC0,&_LC101,uVar2,&_LC0);
    iVar1 = 1;
  }
  else {
    if (*(int *)(zdo_args + 0x34) != 0) {
      cmd_zb_match_desc(param_1 + -2,param_2 + 8);
    }
    if (*(int *)(DAT_0001456c + 0x34) != 0) {
      cmd_zb_simple_desc(param_1 + -2,param_2 + 8);
    }
    if (*(int *)(DAT_00014570 + 0x34) != 0) {
      cmd_zb_active_ep(param_1 + -2,param_2 + 8);
    }
    if (*(int *)(DAT_00014574 + 0x34) != 0) {
      cmd_zb_nwk_addr(param_1 + -2,param_2 + 8);
    }
    if (*(int *)(DAT_00014578 + 0x34) != 0) {
      cmd_zb_ieee_addr(param_1 + -2,param_2 + 8);
    }
    if (*(int *)(DAT_0001457c + 0x34) != 0) {
      cmd_zb_eui64(param_1 + -2,param_2 + 8);
    }
    if (*(int *)(DAT_00014580 + 0x34) != 0) {
      cmd_zb_short(param_1,param_2);
    }
    if (*(int *)(DAT_00014584 + 0x34) != 0) {
      cmd_zb_bind(param_1 + -2,param_2 + 8);
    }
    if (*(int *)(DAT_00014588 + 0x34) != 0) {
      cmd_zb_mgmt_bind(param_1 + -2,param_2 + 8);
    }
    if (*(int *)(DAT_0001458c + 0x34) != 0) {
      cmd_zb_mgmt_leave(param_1 + -2,param_2 + 8);
    }
    iVar1 = *(int *)(DAT_00014590 + 0x34);
    if (iVar1 != 0) {
      cmd_zb_mgmt_lqi(param_1 + -2,param_2 + 8);
      iVar1 = 0;
    }
  }
  return iVar1;
}

