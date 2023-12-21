/*
 * Last changed at upstream commit 790bc8d6ece1bf5f739debaa4aa4af508982070a
 * https://github.com/espressif/esp-zigbee-sdk/commit/790bc8d6ece1bf5f739debaa4aa4af508982070a
 * Upstream date: 2023-12-21 19:52:25 +0800
 * Upstream subject: esp-zigbee-sdk: release/v1.0.7(bdde218a)
 * Source: libesp_zb_cli_command -> zb_esp_cli_cmd_zdo.o -> cmd_zb_mgmt_leave_parse
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int cmd_zb_mgmt_leave_parse(undefined1 *param_1,uint param_2,undefined4 *param_3)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  uint uVar5;
  char *__s1;
  undefined1 auStack_22 [6];
  
  *param_1 = 0;
  param_1[1] = 0;
  param_1[2] = 0;
  param_1[3] = 0;
  param_1[4] = 0;
  param_1[5] = 0;
  param_1[6] = 0;
  param_1[7] = 0;
  param_1[8] = 0;
  param_1[9] = 0;
  param_1[10] = 0;
  if (param_2 == 0) {
    uVar4 = esp_log_timestamp();
    esp_log_write(1,&_LC0,&_L0,uVar4,&_LC0);
    iVar2 = 0;
  }
  else {
    iVar2 = parse_hex_u16(*param_3,auStack_22);
    if (iVar2 == 0) {
      uVar4 = esp_log_timestamp();
      esp_log_write(1,&_LC0,&_LC40,uVar4,&_LC0);
    }
    else {
      param_1[8] = (char)auStack_22._0_2_;
      param_1[9] = SUB21(auStack_22._0_2_,1);
      if (param_2 < 2) {
        uVar5 = 1;
      }
      else if (*(char *)param_3[1] == 'r') {
        uVar5 = 1;
      }
      else if (*(char *)param_3[1] == 'c') {
        uVar5 = 1;
      }
      else {
        iVar3 = parse_address(param_1,3);
        if (iVar3 == 0) {
          uVar4 = esp_log_timestamp();
          esp_log_write(1,&_LC0,&_LC41,uVar4,&_LC0);
          return 0;
        }
        uVar5 = 2;
      }
      while (uVar1 = uVar5 + 1, uVar1 <= param_2) {
        __s1 = (char *)param_3[uVar5];
        iVar3 = strcmp(__s1,"children");
        uVar5 = uVar1;
        if (iVar3 == 0) {
          param_1[10] = param_1[10] | 0x40;
        }
        else {
          iVar3 = strcmp(__s1,"rejoin");
          if (iVar3 != 0) {
            uVar4 = esp_log_timestamp();
            esp_log_write(1,&_LC0,&_LC44,uVar4,&_LC0);
            return 0;
          }
          param_1[10] = param_1[10] | 0x80;
        }
      }
    }
  }
  return iVar2;
}

