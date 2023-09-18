/*
 * Last changed at upstream commit 6ae0a43e13050e8f86079b96ed5a30faf92bdf3c
 * https://github.com/espressif/esp-zigbee-sdk/commit/6ae0a43e13050e8f86079b96ed5a30faf92bdf3c
 * Upstream date: 2023-09-18 10:30:22 +0800
 * Upstream subject: esp-zigbee-sdk: add zigbee trace support and assert support(8c01f3c7)
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
    esp_log_write(1,&_LC3,&_LC104,uVar2,&_LC3);
    iVar1 = 1;
  }
  else {
    if (*(int *)(zdo_args + 0x34) != 0) {
      cmd_zb_match_desc(param_1 + -2,param_2 + 8);
    }
    if (*(int *)(DAT_00014558 + 0x34) != 0) {
      cmd_zb_simple_desc(param_1 + -2,param_2 + 8);
    }
    if (*(int *)(DAT_0001455c + 0x34) != 0) {
      cmd_zb_active_ep(param_1 + -2,param_2 + 8);
    }
    if (*(int *)(DAT_00014560 + 0x34) != 0) {
      cmd_zb_nwk_addr(param_1 + -2,param_2 + 8);
    }
    if (*(int *)(DAT_00014564 + 0x34) != 0) {
      cmd_zb_ieee_addr(param_1 + -2,param_2 + 8);
    }
    if (*(int *)(DAT_00014568 + 0x34) != 0) {
      cmd_zb_eui64(param_1 + -2,param_2 + 8);
    }
    if (*(int *)(DAT_0001456c + 0x34) != 0) {
      cmd_zb_short(param_1,param_2);
    }
    if (*(int *)(DAT_00014570 + 0x34) != 0) {
      cmd_zb_bind(param_1 + -2,param_2 + 8);
    }
    if (*(int *)(DAT_00014574 + 0x34) != 0) {
      cmd_zb_mgmt_bind(param_1 + -2,param_2 + 8);
    }
    if (*(int *)(DAT_00014578 + 0x34) != 0) {
      cmd_zb_mgmt_leave(param_1 + -2,param_2 + 8);
    }
    iVar1 = *(int *)(DAT_0001457c + 0x34);
    if (iVar1 != 0) {
      cmd_zb_mgmt_lqi(param_1 + -2,param_2 + 8);
      iVar1 = 0;
    }
  }
  return iVar1;
}

