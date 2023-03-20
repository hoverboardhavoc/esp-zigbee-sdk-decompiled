/*
 * Last changed at upstream commit 8f416d47159477fb2dfe72f817700bc25debb587
 * https://github.com/espressif/esp-zigbee-sdk/commit/8f416d47159477fb2dfe72f817700bc25debb587
 * Upstream date: 2023-03-20 14:23:27 +0800
 * Upstream subject: zcl: support more ZCL cluster(caef391)
 * Source: libesp_zb_cli_command -> zb_esp_cli_cmd_zcl_attr.o -> print_write_attr_response
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void print_write_attr_response(undefined4 param_1)

{
  char *pcVar1;
  int iVar2;
  undefined4 uVar3;
  uint uVar4;
  uint uVar5;
  
  iVar2 = zb_buf_len_func();
  if (iVar2 == 0) {
    pcVar1 = (char *)0x0;
  }
  else {
    pcVar1 = (char *)zb_buf_begin_func(param_1);
    if (pcVar1 == (char *)0x0) goto _L0;
    iVar2 = zb_zcl_zcl8_statuses_conversion(*pcVar1);
    *pcVar1 = (char)iVar2;
    if (iVar2 == 0) {
      uVar5 = 1;
    }
    else {
      zb_buf_len_func(param_1);
      uVar5 = 3;
    }
    uVar4 = zb_buf_len_func(param_1);
    if (uVar4 < uVar5) goto _L0;
    zb_buf_cut_left_func(param_1,uVar5);
  }
  if (pcVar1 != (char *)0x0) {
    if (*pcVar1 == '\0') {
      uVar3 = esp_log_timestamp();
      esp_log_write(3,&_L0,&_LC3,uVar3,&_L0);
      return;
    }
    uVar3 = esp_log_timestamp();
    esp_log_write(1,&_L0,&_LC2,uVar3,&_L0,*pcVar1);
    return;
  }
_L0:
  uVar3 = esp_log_timestamp();
  esp_log_write(1,&_L0,&_LC1,uVar3,&_L0);
  return;
}

