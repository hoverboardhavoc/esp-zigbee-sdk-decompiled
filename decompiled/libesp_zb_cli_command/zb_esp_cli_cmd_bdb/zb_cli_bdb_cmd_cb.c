/*
 * Last changed at upstream commit fdd7b02c333322a6b0be71e313fe2aad2eac22c5
 * https://github.com/espressif/esp-zigbee-sdk/commit/fdd7b02c333322a6b0be71e313fe2aad2eac22c5
 * Upstream date: 2023-08-11 14:15:41 +0800
 * Upstream subject: esp-zigbee-sdk: release/v0.9.0(793f8578)
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
    arg_print_errors(*(undefined4 *)(iVar2 + 0xc),DAT_0001211c,*param_2);
    return 1;
  }
  if (1 < param_1) {
    if (*(int *)(bdb_args + 0x34) != 0) {
      cmd_zb_role(**(undefined4 **)(bdb_args + 0x38));
    }
    if (*(int *)(DAT_000120f8 + 0x34) != 0) {
      cmd_zb_start();
    }
    if (*(int *)(DAT_000120f0 + 0x34) != 0) {
      cmd_zb_extpanid(**(undefined4 **)(DAT_000120f0 + 0x38));
    }
    if (*(int *)(DAT_000120f4 + 0x34) != 0) {
      cmd_zb_panid(**(undefined4 **)(DAT_000120f4 + 0x38));
    }
    if (*(int *)(DAT_000120fc + 0x34) != 0) {
      cmd_zb_channel(**(undefined4 **)(DAT_000120fc + 0x38));
    }
    if ((*(int *)(DAT_00012100 + 0x34) != 0) &&
       (pcVar1 = (char *)**(undefined4 **)(DAT_00012100 + 0x38), pcVar1 != (char *)0x0)) {
      iVar2 = strcmp(pcVar1,"add");
      if (iVar2 == 0) {
        if ((*(int *)(DAT_00012104 + 0x34) == 0) || (*(int *)(DAT_00012108 + 0x34) == 0)) {
          uVar3 = esp_log_timestamp();
          esp_log_write(1,0x10000,&_LC50,uVar3,0x10000);
        }
        else {
          cmd_zb_install_code(pcVar1,**(undefined4 **)(DAT_00012104 + 0x38),
                              **(undefined4 **)(DAT_00012108 + 0x38));
        }
      }
      pcVar1 = (char *)**(undefined4 **)(DAT_00012100 + 0x38);
      iVar2 = strcmp(pcVar1,"set");
      if ((iVar2 == 0) && (*(int *)(DAT_00012104 + 0x34) != 0)) {
        cmd_zb_install_code(pcVar1,**(undefined4 **)(DAT_00012104 + 0x38),0);
      }
      pcVar1 = (char *)**(undefined4 **)(DAT_00012100 + 0x38);
      iVar2 = strcmp(pcVar1,"policy");
      if ((iVar2 == 0) && (*(int *)(DAT_00012104 + 0x34) != 0)) {
        cmd_zb_install_code(pcVar1,**(undefined4 **)(DAT_00012104 + 0x38),0);
      }
    }
    if (*(int *)(DAT_0001210c + 0x34) != 0) {
      cmd_zb_legacy(**(undefined4 **)(DAT_0001210c + 0x38));
    }
    if (*(int *)(DAT_00012110 + 0x34) != 0) {
      cmd_zb_nwkkey(**(undefined4 **)(DAT_00012110 + 0x38));
    }
    if (*(int *)(DAT_00012114 + 0x34) != 0) {
      cmd_zb_factory_reset();
    }
    iVar2 = *(int *)(DAT_00012118 + 0x34);
    if (iVar2 != 0) {
      cmd_zb_child_max(**(undefined4 **)(DAT_00012118 + 0x38));
      iVar2 = 0;
    }
    return iVar2;
  }
  uVar3 = esp_log_timestamp();
  esp_log_write(1,0x10000,&_LC49,uVar3,0x10000);
  return 1;
}

