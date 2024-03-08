/*
 * Last changed at upstream commit 2fe15bae2e4382ac99f249a0934066f5d5a5c684
 * https://github.com/espressif/esp-zigbee-sdk/commit/2fe15bae2e4382ac99f249a0934066f5d5a5c684
 * Upstream date: 2024-03-08 17:10:04 +0800
 * Upstream subject: esp-zigbee-sdk: release/v1.2.0(9d7e9ff2)
 * Source: libesp_zb_cli_command -> zb_esp_cli_cmd_bdb.o -> zb_cli_bdb_cmd_cb
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int zb_cli_bdb_cmd_cb(int param_1,undefined4 *param_2)

{
  char *pcVar1;
  int iVar2;
  undefined4 uVar3;
  
  iVar2 = arg_parse(&bdb_args);
  if (iVar2 != 0) {
    iVar2 = __getreent();
    arg_print_errors(*(undefined4 *)(iVar2 + 0xc),DAT_00014880,*param_2);
    return 1;
  }
  if (1 < param_1) {
    if (*(int *)(DAT_00014840 + 0x34) != 0) {
      cmd_zb_role(**(undefined4 **)(DAT_00014840 + 0x38));
    }
    if (*(int *)(DAT_00014844 + 0x34) != 0) {
      cmd_zb_nwk_type(**(undefined4 **)(DAT_00014844 + 0x38));
    }
    if (*(int *)(DAT_00014850 + 0x34) != 0) {
      cmd_zb_start(param_1 + -2,param_2 + 2);
    }
    if (*(int *)(DAT_00014854 + 0x34) != 0) {
      cmd_zb_nwk_commissioning(**(undefined4 **)(DAT_00014854 + 0x38));
    }
    if (*(int *)(DAT_00014848 + 0x34) != 0) {
      cmd_zb_extpanid(**(undefined4 **)(DAT_00014848 + 0x38));
    }
    if (*(int *)(DAT_0001484c + 0x34) != 0) {
      cmd_zb_panid(**(undefined4 **)(DAT_0001484c + 0x38));
    }
    if (*(int *)(DAT_00014858 + 0x34) != 0) {
      cmd_zb_nwk_state(param_1 + -2,param_2 + 2);
    }
    if (*(int *)(DAT_0001485c + 0x34) != 0) {
      cmd_zb_channel(**(undefined4 **)(DAT_0001485c + 0x38));
    }
    if (*(int *)(DAT_00014860 + 0x34) != 0) {
      cmd_zb_channel_mask(param_1 + -2,param_2 + 2);
    }
    if ((*(int *)(DAT_00014864 + 0x34) != 0) &&
       (pcVar1 = (char *)**(undefined4 **)(DAT_00014864 + 0x38), pcVar1 != (char *)0x0)) {
      iVar2 = strcmp(pcVar1,"add");
      if (iVar2 == 0) {
        if ((*(int *)(DAT_00014868 + 0x34) == 0) || (*(int *)(DAT_0001486c + 0x34) == 0)) {
          uVar3 = esp_log_timestamp();
          esp_log_write(1,0x10000,&_L0,uVar3,0x10000);
        }
        else {
          cmd_zb_install_code(pcVar1,**(undefined4 **)(DAT_00014868 + 0x38),
                              **(undefined4 **)(DAT_0001486c + 0x38));
        }
      }
      pcVar1 = (char *)**(undefined4 **)(DAT_00014864 + 0x38);
      iVar2 = strcmp(pcVar1,"set");
      if ((iVar2 == 0) && (*(int *)(DAT_00014868 + 0x34) != 0)) {
        cmd_zb_install_code(pcVar1,**(undefined4 **)(DAT_00014868 + 0x38),0);
      }
      pcVar1 = (char *)**(undefined4 **)(DAT_00014864 + 0x38);
      iVar2 = strcmp(pcVar1,"policy");
      if ((iVar2 == 0) && (*(int *)(DAT_00014868 + 0x34) != 0)) {
        cmd_zb_install_code(pcVar1,**(undefined4 **)(DAT_00014868 + 0x38),0);
      }
    }
    if (*(int *)(DAT_00014870 + 0x34) != 0) {
      cmd_zb_legacy(**(undefined4 **)(DAT_00014870 + 0x38));
    }
    if (*(int *)(DAT_00014874 + 0x34) != 0) {
      cmd_zb_nwkkey(**(undefined4 **)(DAT_00014874 + 0x38));
    }
    if (*(int *)(DAT_00014878 + 0x34) != 0) {
      cmd_zb_factory_reset(**(undefined4 **)(DAT_00014878 + 0x38));
    }
    if (*(int *)(DAT_0001487c + 0x34) != 0) {
      cmd_zb_child_max(**(undefined4 **)(DAT_0001487c + 0x38));
    }
    iVar2 = *(int *)(bdb_args + 0x34);
    if (iVar2 != 0) {
      uVar3 = esp_log_timestamp();
      esp_log_write(1,0x10000,&_LC115,uVar3,0x10000);
      iVar2 = 0;
    }
    return iVar2;
  }
  uVar3 = esp_log_timestamp();
  esp_log_write(1,0x10000,&_LC110,uVar3,0x10000);
  return 1;
}

