/*
 * Last changed at upstream commit 55d58f0243c7dca5c0887a2b065178dacc2d00be
 * https://github.com/espressif/esp-zigbee-sdk/commit/55d58f0243c7dca5c0887a2b065178dacc2d00be
 * Upstream date: 2022-11-15 14:25:21 +0800
 * Upstream subject: cli: Add cli example
 * Source: libesp_zb_cli_command -> zb_esp_cli_cmd_zcl_attr_report.o -> print_attr_update
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void print_attr_update(char *param_1,undefined4 param_2)

{
  undefined2 *puVar1;
  int iVar2;
  undefined4 uVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  undefined1 auStack_120 [264];
  
  if (*param_1 == '\0') {
    uVar3 = esp_log_timestamp();
    esp_log_write(3,&_L0,&_LC2,uVar3,&_L0,*(undefined2 *)(param_1 + 1));
  }
  else {
    iVar2 = ieee_addr_to_str(auStack_120,0xff,param_1 + 1);
    if (iVar2 < 0) {
      uVar3 = esp_log_timestamp();
      esp_log_write(3,&_L0,&_LC3,uVar3,&_L0);
    }
    else {
      uVar3 = esp_log_timestamp();
      esp_log_write(3,&_L0,&_LC4,uVar3,&_L0,auStack_120);
    }
  }
  uVar4 = zb_buf_len_func(param_2);
  if (uVar4 < 4) {
    puVar1 = (undefined2 *)0x0;
  }
  else {
    puVar1 = (undefined2 *)zb_buf_begin_func(param_2);
    if (puVar1 != (undefined2 *)0x0) {
      iVar2 = zb_zcl_get_attribute_size(*(undefined1 *)(puVar1 + 1),(int)puVar1 + 3);
      uVar4 = iVar2 + 3U & 0xff;
      zb_buf_len_func(param_2);
      uVar6 = zb_buf_len_func(param_2);
      if (uVar6 < uVar4) {
        puVar1 = (undefined2 *)0x0;
      }
      else {
        zb_buf_cut_left_func(param_2,uVar4);
      }
    }
  }
  iVar2 = 0;
  while( true ) {
    do {
      while( true ) {
        if (puVar1 == (undefined2 *)0x0) {
          return;
        }
        iVar2 = zcl_attr_to_str(auStack_120 + iVar2,0xffU - iVar2 & 0xffff,
                                *(undefined1 *)(puVar1 + 1),(int)puVar1 + 3);
        if (iVar2 < 0) {
          uVar3 = esp_log_timestamp();
          esp_log_write(1,&_L0,&_LC5,uVar3,&_L0);
        }
        else {
          uVar3 = esp_log_timestamp();
          esp_log_write(3,&_L0,&_LC6,uVar3,&_L0,*(undefined2 *)(param_1 + 0x10),
                        *(undefined2 *)(param_1 + 0xe),*puVar1);
        }
        uVar4 = zb_buf_len_func(param_2);
        if (3 < uVar4) break;
        puVar1 = (undefined2 *)0x0;
      }
      puVar1 = (undefined2 *)zb_buf_begin_func(param_2);
    } while (puVar1 == (undefined2 *)0x0);
    iVar5 = zb_zcl_get_attribute_size(*(undefined1 *)(puVar1 + 1),(int)puVar1 + 3);
    uVar6 = iVar5 + 3U & 0xff;
    zb_buf_len_func(param_2);
    uVar4 = zb_buf_len_func(param_2);
    if (uVar4 < uVar6) break;
    zb_buf_cut_left_func(param_2,uVar6);
  }
  return;
}

