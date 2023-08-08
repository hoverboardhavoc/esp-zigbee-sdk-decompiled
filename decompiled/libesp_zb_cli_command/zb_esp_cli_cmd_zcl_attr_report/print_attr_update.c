/*
 * Last changed at upstream commit d04ab25a7353bae74042267d24c5fef5f02d0726
 * https://github.com/espressif/esp-zigbee-sdk/commit/d04ab25a7353bae74042267d24c5fef5f02d0726
 * Upstream date: 2023-08-08 16:02:31 +0800
 * Upstream subject: esp-zigbee-sdk: add touchlink example
 * Source: libesp_zb_cli_command -> zb_esp_cli_cmd_zcl_attr_report.o -> print_attr_update
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void print_attr_update(char *param_1,undefined4 param_2)

{
  undefined2 *puVar1;
  undefined4 uVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  undefined1 auStack_120 [264];
  
  if (*param_1 == '\0') {
    uVar2 = esp_log_timestamp();
    esp_log_write(3,&_L0,&_LC2,uVar2,&_L0,*(undefined2 *)(param_1 + 1));
  }
  else {
    iVar6 = ieee_addr_to_str(auStack_120,0xff,param_1 + 1);
    if (iVar6 < 0) {
      uVar2 = esp_log_timestamp();
      esp_log_write(3,&_L0,&_LC3,uVar2,&_L0);
    }
    else {
      uVar2 = esp_log_timestamp();
      esp_log_write(3,&_L0,&_LC4,uVar2,&_L0,auStack_120);
    }
  }
  uVar3 = zb_buf_len_func(param_2);
  if (uVar3 < 4) {
    puVar1 = (undefined2 *)0x0;
  }
  else {
    puVar1 = (undefined2 *)zb_buf_begin_func(param_2);
    if (puVar1 != (undefined2 *)0x0) {
      iVar6 = zb_zcl_get_attribute_size(*(undefined1 *)(puVar1 + 1),(int)puVar1 + 3);
      uVar3 = iVar6 + 3U & 0xff;
      zb_buf_len_func(param_2);
      uVar5 = zb_buf_len_func(param_2);
      if (uVar5 < uVar3) {
        puVar1 = (undefined2 *)0x0;
      }
      else {
        zb_buf_cut_left_func(param_2,uVar3);
      }
    }
  }
  iVar6 = 0;
  while( true ) {
    if (puVar1 == (undefined2 *)0x0) {
      return;
    }
    iVar6 = zcl_attr_to_str(auStack_120 + iVar6,0xffU - iVar6 & 0xffff,*(undefined1 *)(puVar1 + 1),
                            (int)puVar1 + 3);
    if (iVar6 < 0) {
      uVar2 = esp_log_timestamp();
      esp_log_write(1,&_L0,&_LC5,uVar2,&_L0);
    }
    else {
      uVar2 = esp_log_timestamp();
      esp_log_write(3,&_L0,&_LC6,uVar2,&_L0,*(undefined2 *)(param_1 + 0x11),
                    *(undefined2 *)(param_1 + 0xf),*puVar1);
    }
    uVar3 = zb_buf_len_func(param_2);
    if (uVar3 < 4) {
      puVar1 = (undefined2 *)0x0;
    }
    else {
      puVar1 = (undefined2 *)zb_buf_begin_func(param_2);
    }
    if (puVar1 == (undefined2 *)0x0) break;
    iVar4 = zb_zcl_get_attribute_size(*(undefined1 *)(puVar1 + 1),(int)puVar1 + 3);
    uVar3 = iVar4 + 3U & 0xff;
    zb_buf_len_func(param_2);
    uVar5 = zb_buf_len_func(param_2);
    if (uVar5 < uVar3) {
      return;
    }
    zb_buf_cut_left_func(param_2,uVar3);
  }
  return;
}

