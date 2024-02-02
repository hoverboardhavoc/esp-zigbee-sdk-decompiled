/*
 * Last changed at upstream commit f9cc2dccd1062ffdf8f9e034d227fe83c0a1712e
 * https://github.com/espressif/esp-zigbee-sdk/commit/f9cc2dccd1062ffdf8f9e034d227fe83c0a1712e
 * Upstream date: 2024-02-02 22:17:34 +0800
 * Upstream subject: esp-zigbee-sdk: release/v1.1.0(5362d771)
 * Source: libesp_zb_cli_command -> zb_esp_cli_cmd_bdb.o -> zb_cli_tlk_cmd_cb
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int zb_cli_tlk_cmd_cb(int param_1,undefined4 *param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = arg_parse(&tlk_args);
  if (iVar1 == 0) {
    if (param_1 < 2) {
      uVar2 = esp_log_timestamp();
      esp_log_write(1,0x10000,&_LC104,uVar2,0x10000);
      iVar1 = 1;
    }
    else {
      if (*(int *)(tlk_args + 0x34) != 0) {
        cmd_zb_tlk_set_timeout(param_1 + -2,param_2 + 2);
      }
      if (*(int *)(DAT_00014854 + 0x34) != 0) {
        cmd_zb_tlk_set_rssi(param_1 + -2,param_2 + 2);
      }
      iVar1 = *(int *)(DAT_00014858 + 0x34);
      if (iVar1 != 0) {
        cmd_zb_tlk_set_master_key(param_1 + -2,param_2 + 2);
        iVar1 = 0;
      }
    }
  }
  else {
    iVar1 = __getreent();
    arg_print_errors(*(undefined4 *)(iVar1 + 0xc),DAT_0001485c,*param_2);
    iVar1 = 1;
  }
  return iVar1;
}

