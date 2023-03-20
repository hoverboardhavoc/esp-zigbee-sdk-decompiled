/*
 * Last changed at upstream commit 8f416d47159477fb2dfe72f817700bc25debb587
 * https://github.com/espressif/esp-zigbee-sdk/commit/8f416d47159477fb2dfe72f817700bc25debb587
 * Upstream date: 2023-03-20 14:23:27 +0800
 * Upstream subject: zcl: support more ZCL cluster(caef391)
 * Source: libesp_zb_cli_command -> zb_esp_cli_cmd_zdo.o -> cmd_zb_ieee_addr
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void cmd_zb_ieee_addr(int param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  int iVar2;
  undefined2 *puVar3;
  int iVar4;
  int iVar5;
  undefined2 uStack_12;
  
  if (param_1 == 1) {
    iVar2 = zb_buf_get_out_func();
    if (iVar2 == 0) {
      uVar1 = esp_log_timestamp();
      esp_log_write(1,&_LC3,&_LC38,uVar1,&_LC3);
    }
    else {
      puVar3 = (undefined2 *)zb_buf_get_tail_func(6);
      *(undefined1 *)((int)puVar3 + 5) = 0;
      *(undefined1 *)(puVar3 + 2) = 0;
      iVar4 = parse_hex_u16(*param_2,&uStack_12);
      if (iVar4 == 0) {
        uVar1 = esp_log_timestamp();
        esp_log_write(1,&_LC3,&_LC39,uVar1,&_LC3);
      }
      else {
        puVar3[1] = uStack_12;
        *puVar3 = uStack_12;
        iVar4 = get_free_ctx();
        if (iVar4 == 0) {
          uVar1 = esp_log_timestamp();
          esp_log_write(1,&_LC3,&_LC40,uVar1,&_LC3);
        }
        else {
          iVar5 = zb_zdo_ieee_addr_req(iVar2,cmd_zb_ieee_addr_cb);
          *(char *)(iVar4 + 4) = (char)iVar5;
          if (iVar5 != 0xff) {
            iVar2 = zb_schedule_app_alarm(cmd_zb_ieee_addr_timeout,0x14a);
            if (iVar2 == 0) {
              return;
            }
            uVar1 = esp_log_timestamp();
            esp_log_write(1,&_LC3,&_LC45,uVar1,&_LC3);
            invalidate_ctx(iVar4);
            return;
          }
          uVar1 = esp_log_timestamp(0xff);
          esp_log_write(1,&_LC3,&_LC44,uVar1,&_LC3);
        }
        if (iVar4 != 0) {
          invalidate_ctx(iVar4);
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

