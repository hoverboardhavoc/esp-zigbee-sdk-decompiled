/*
 * Last changed at upstream commit 6ae0a43e13050e8f86079b96ed5a30faf92bdf3c
 * https://github.com/espressif/esp-zigbee-sdk/commit/6ae0a43e13050e8f86079b96ed5a30faf92bdf3c
 * Upstream date: 2023-09-18 10:30:22 +0800
 * Upstream subject: esp-zigbee-sdk: add zigbee trace support and assert support(8c01f3c7)
 * Source: libesp_zb_cli_command -> zb_esp_cli_cmd_zdo.o -> cmd_zb_active_ep
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void cmd_zb_active_ep(int param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  int iVar2;
  undefined1 *puVar3;
  int iVar4;
  int iVar5;
  undefined1 auStack_12 [2];
  
  if (param_1 == 1) {
    iVar2 = zb_buf_get_out_func();
    if (iVar2 == 0) {
      uVar1 = esp_log_timestamp();
      esp_log_write(1,&_LC3,&_LC34,uVar1,&_LC3);
    }
    else {
      puVar3 = (undefined1 *)zb_buf_initial_alloc_func(2);
      iVar4 = parse_hex_u16(*param_2,auStack_12);
      if (iVar4 == 0) {
        uVar1 = esp_log_timestamp();
        esp_log_write(1,&_LC3,&_LC35,uVar1,&_LC3);
      }
      else {
        *puVar3 = auStack_12[0];
        puVar3[1] = auStack_12[1];
        iVar4 = get_free_ctx();
        if (iVar4 == 0) {
          uVar1 = esp_log_timestamp();
          esp_log_write(1,&_LC3,&_LC36,uVar1,&_LC3);
        }
        else {
          iVar5 = zb_zdo_active_ep_req(iVar2,cmd_zb_active_ep_cb);
          *(char *)(iVar4 + 4) = (char)iVar5;
          if (iVar5 != 0xff) {
            return;
          }
          uVar1 = esp_log_timestamp();
          esp_log_write(1,&_LC3,&_LC37,uVar1,&_LC3);
        }
      }
      zb_buf_free_func(iVar2);
    }
  }
  else {
    uVar1 = esp_log_timestamp();
    esp_log_write(1,&_LC3,&_L0,uVar1,&_LC3);
  }
  return;
}

