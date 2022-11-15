/*
 * Last changed at upstream commit 55d58f0243c7dca5c0887a2b065178dacc2d00be
 * https://github.com/espressif/esp-zigbee-sdk/commit/55d58f0243c7dca5c0887a2b065178dacc2d00be
 * Upstream date: 2022-11-15 14:25:21 +0800
 * Upstream subject: cli: Add cli example
 * Source: libesp_zb_cli_command -> zb_esp_cli_cmd_zdo.o -> cmd_zb_mgmt_leave_parse
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int cmd_zb_mgmt_leave_parse(undefined1 *param_1,uint param_2,undefined4 *param_3)

{
  char *pcVar1;
  uint uVar2;
  size_t sVar3;
  int iVar4;
  int iVar5;
  undefined4 uVar6;
  uint uVar7;
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
    uVar6 = esp_log_timestamp();
    esp_log_write(1,&_LC3,&_LC50,uVar6,&_LC3);
    iVar4 = 0;
  }
  else {
    pcVar1 = (char *)*param_3;
    sVar3 = strlen(pcVar1);
    iVar4 = parse_hex_str(pcVar1,sVar3 & 0xff,auStack_22,2,1);
    if (iVar4 == 0) {
      uVar6 = esp_log_timestamp();
      esp_log_write(1,&_LC3,&_LC51,uVar6,&_LC3);
    }
    else {
      param_1[8] = (char)auStack_22._0_2_;
      param_1[9] = SUB21(auStack_22._0_2_,1);
      if (param_2 < 2) {
        uVar7 = 1;
      }
      else if (*(char *)param_3[1] == 'r') {
        uVar7 = 1;
      }
      else if (*(char *)param_3[1] == 'c') {
        uVar7 = 1;
      }
      else {
        iVar5 = parse_address(param_1,3);
        if (iVar5 == 0) {
          uVar6 = esp_log_timestamp();
          esp_log_write(1,&_LC3,&_LC52,uVar6,&_LC3);
          return 0;
        }
        uVar7 = 2;
      }
      while (uVar2 = uVar7 + 1, uVar2 <= param_2) {
        pcVar1 = (char *)param_3[uVar7];
        iVar5 = strcmp(pcVar1,"children");
        uVar7 = uVar2;
        if (iVar5 == 0) {
          param_1[10] = param_1[10] | 0x40;
        }
        else {
          iVar5 = strcmp(pcVar1,"rejoin");
          if (iVar5 != 0) {
            uVar6 = esp_log_timestamp();
            esp_log_write(1,&_LC3,&_LC55,uVar6,&_LC3);
            return 0;
          }
          param_1[10] = param_1[10] | 0x80;
        }
      }
    }
  }
  return iVar4;
}

