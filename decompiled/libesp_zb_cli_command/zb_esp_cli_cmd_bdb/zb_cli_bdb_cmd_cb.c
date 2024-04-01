/*
 * Last changed at upstream commit 3128a1de3a8a176dac99e12775a60287e9d10fd7
 * https://github.com/espressif/esp-zigbee-sdk/commit/3128a1de3a8a176dac99e12775a60287e9d10fd7
 * Upstream date: 2024-04-01 17:59:07 +0800
 * Upstream subject: esp-zigbee-sdk: release/v1.2.2(4a0e02cc)
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
    arg_print_errors(*(undefined4 *)(iVar2 + 0xc),DAT_00014870,*param_2);
    return 1;
  }
  if (1 < param_1) {
    if (*(int *)(DAT_00014830 + 0x34) != 0) {
      cmd_zb_role(**(undefined4 **)(DAT_00014830 + 0x38));
    }
    if (*(int *)(DAT_00014834 + 0x34) != 0) {
      cmd_zb_nwk_type(**(undefined4 **)(DAT_00014834 + 0x38));
    }
    if (*(int *)(DAT_00014840 + 0x34) != 0) {
      cmd_zb_start(param_1 + -2,param_2 + 2);
    }
    if (*(int *)(DAT_00014844 + 0x34) != 0) {
      cmd_zb_nwk_commissioning(**(undefined4 **)(DAT_00014844 + 0x38));
    }
    if (*(int *)(DAT_00014838 + 0x34) != 0) {
      cmd_zb_extpanid(**(undefined4 **)(DAT_00014838 + 0x38));
    }
    if (*(int *)(DAT_0001483c + 0x34) != 0) {
      cmd_zb_panid(**(undefined4 **)(DAT_0001483c + 0x38));
    }
    if (*(int *)(DAT_00014848 + 0x34) != 0) {
      cmd_zb_nwk_state(param_1 + -2,param_2 + 2);
    }
    if (*(int *)(DAT_0001484c + 0x34) != 0) {
      cmd_zb_channel(**(undefined4 **)(DAT_0001484c + 0x38));
    }
    if (*(int *)(DAT_00014850 + 0x34) != 0) {
      cmd_zb_channel_mask(param_1 + -2,param_2 + 2);
    }
    if ((*(int *)(DAT_00014854 + 0x34) != 0) &&
       (pcVar1 = (char *)**(undefined4 **)(DAT_00014854 + 0x38), pcVar1 != (char *)0x0)) {
      iVar2 = strcmp(pcVar1,"add");
      if (iVar2 == 0) {
        if ((*(int *)(DAT_00014858 + 0x34) == 0) || (*(int *)(DAT_0001485c + 0x34) == 0)) {
          uVar3 = esp_log_timestamp();
          esp_log_write(1,0x10000,&_L0,uVar3,0x10000);
        }
        else {
          cmd_zb_install_code(pcVar1,**(undefined4 **)(DAT_00014858 + 0x38),
                              **(undefined4 **)(DAT_0001485c + 0x38));
        }
      }
      pcVar1 = (char *)**(undefined4 **)(DAT_00014854 + 0x38);
      iVar2 = strcmp(pcVar1,"set");
      if ((iVar2 == 0) && (*(int *)(DAT_00014858 + 0x34) != 0)) {
        cmd_zb_install_code(pcVar1,**(undefined4 **)(DAT_00014858 + 0x38),0);
      }
      pcVar1 = (char *)**(undefined4 **)(DAT_00014854 + 0x38);
      iVar2 = strcmp(pcVar1,"policy");
      if ((iVar2 == 0) && (*(int *)(DAT_00014858 + 0x34) != 0)) {
        cmd_zb_install_code(pcVar1,**(undefined4 **)(DAT_00014858 + 0x38),0);
      }
    }
    if (*(int *)(DAT_00014860 + 0x34) != 0) {
      cmd_zb_legacy(**(undefined4 **)(DAT_00014860 + 0x38));
    }
    if (*(int *)(DAT_00014864 + 0x34) != 0) {
      cmd_zb_nwkkey(**(undefined4 **)(DAT_00014864 + 0x38));
    }
    if (*(int *)(DAT_00014868 + 0x34) != 0) {
      cmd_zb_factory_reset(**(undefined4 **)(DAT_00014868 + 0x38));
    }
    if (*(int *)(DAT_0001486c + 0x34) != 0) {
      cmd_zb_child_max(**(undefined4 **)(DAT_0001486c + 0x38));
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

