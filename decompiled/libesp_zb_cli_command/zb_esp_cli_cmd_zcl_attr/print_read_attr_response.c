/*
 * Last changed at upstream commit 55d58f0243c7dca5c0887a2b065178dacc2d00be
 * https://github.com/espressif/esp-zigbee-sdk/commit/55d58f0243c7dca5c0887a2b065178dacc2d00be
 * Upstream date: 2022-11-15 14:25:21 +0800
 * Upstream subject: cli: Add cli example
 * Source: libesp_zb_cli_command -> zb_esp_cli_cmd_zcl_attr.o -> print_read_attr_response
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void print_read_attr_response(undefined4 param_1)

{
  undefined2 *puVar1;
  uint uVar2;
  int iVar3;
  undefined4 uVar4;
  uint uVar5;
  undefined1 auStack_48 [52];
  
  uVar2 = zb_buf_len_func();
  if (uVar2 < 3) {
    puVar1 = (undefined2 *)0x0;
  }
  else {
    puVar1 = (undefined2 *)zb_buf_begin_func(param_1);
    if (puVar1 != (undefined2 *)0x0) {
      iVar3 = zb_zcl_zcl8_statuses_conversion(*(undefined1 *)(puVar1 + 1));
      *(char *)(puVar1 + 1) = (char)iVar3;
      if (iVar3 == 0) {
        iVar3 = zb_zcl_get_attribute_size(*(undefined1 *)((int)puVar1 + 3),puVar1 + 2);
        uVar2 = iVar3 + 4U & 0xff;
        zb_buf_len_func(param_1);
      }
      else {
        uVar2 = 3;
      }
      uVar5 = zb_buf_len_func(param_1);
      if (uVar5 < uVar2) {
        puVar1 = (undefined2 *)0x0;
      }
      else {
        zb_buf_cut_left_func(param_1,uVar2);
      }
    }
  }
  if (*(char *)(puVar1 + 1) == '\0') {
    iVar3 = zcl_attr_to_str(auStack_48,0x28,*(undefined1 *)((int)puVar1 + 3),puVar1 + 2);
    if (iVar3 < 0) {
      uVar4 = esp_log_timestamp();
      esp_log_write(1,&_L0,&_LC4,uVar4,&_L0);
    }
    else {
      uVar4 = esp_log_timestamp();
      esp_log_write(3,&_L0,&_LC5,uVar4,&_L0,*puVar1,*(undefined1 *)((int)puVar1 + 3),auStack_48);
      uVar4 = esp_log_timestamp();
      esp_log_write(3,&_L0,&_LC3,uVar4,&_L0);
    }
  }
  else {
    uVar4 = esp_log_timestamp();
    esp_log_write(1,&_L0,&_LC6,uVar4,&_L0,*(undefined1 *)(puVar1 + 1));
  }
  return;
}

