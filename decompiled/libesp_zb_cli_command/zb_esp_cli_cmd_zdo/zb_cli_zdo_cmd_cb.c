/*
 * Last changed at upstream commit dfdf370f9265e944dde2de8bee7a248c7515f1ef
 * https://github.com/espressif/esp-zigbee-sdk/commit/dfdf370f9265e944dde2de8bee7a248c7515f1ef
 * Upstream date: 2022-12-14 19:24:05 +0800
 * Upstream subject: examples:Add ota application example(986c075)
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
    esp_log_write(1,&_LC3,&_LC103,uVar2,&_LC3);
    iVar1 = 1;
  }
  else {
    if (*(int *)(zdo_args + 0x34) != 0) {
      cmd_zb_match_desc(param_1 + -2,param_2 + 8);
    }
    if (*(int *)(DAT_00014614 + 0x34) != 0) {
      cmd_zb_simple_desc(param_1 + -2,param_2 + 8);
    }
    if (*(int *)(DAT_00014618 + 0x34) != 0) {
      cmd_zb_active_ep(param_1 + -2,param_2 + 8);
    }
    if (*(int *)(DAT_0001461c + 0x34) != 0) {
      cmd_zb_nwk_addr(param_1 + -2,param_2 + 8);
    }
    if (*(int *)(DAT_00014620 + 0x34) != 0) {
      cmd_zb_ieee_addr(param_1 + -2,param_2 + 8);
    }
    if (*(int *)(DAT_00014624 + 0x34) != 0) {
      cmd_zb_eui64(param_1 + -2,param_2 + 8);
    }
    if (*(int *)(DAT_00014628 + 0x34) != 0) {
      cmd_zb_short(param_1,param_2);
    }
    if (*(int *)(DAT_0001462c + 0x34) != 0) {
      cmd_zb_bind(param_1 + -2,param_2 + 8);
    }
    if (*(int *)(DAT_00014630 + 0x34) != 0) {
      cmd_zb_mgmt_bind(param_1 + -2,param_2 + 8);
    }
    if (*(int *)(DAT_00014634 + 0x34) != 0) {
      cmd_zb_mgmt_leave(param_1 + -2,param_2 + 8);
    }
    iVar1 = *(int *)(DAT_00014638 + 0x34);
    if (iVar1 != 0) {
      cmd_zb_mgmt_lqi(param_1 + -2,param_2 + 8);
      iVar1 = 0;
    }
  }
  return iVar1;
}

