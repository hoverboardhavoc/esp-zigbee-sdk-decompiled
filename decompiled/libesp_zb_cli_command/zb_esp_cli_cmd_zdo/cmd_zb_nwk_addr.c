/*
 * Last changed at upstream commit 790bc8d6ece1bf5f739debaa4aa4af508982070a
 * https://github.com/espressif/esp-zigbee-sdk/commit/790bc8d6ece1bf5f739debaa4aa4af508982070a
 * Upstream date: 2023-12-21 19:52:25 +0800
 * Upstream subject: esp-zigbee-sdk: release/v1.0.7(bdde218a)
 * Source: libesp_zb_cli_command -> zb_esp_cli_cmd_zdo.o -> cmd_zb_nwk_addr
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void cmd_zb_nwk_addr(int param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  int iVar2;
  undefined2 *puVar3;
  int iVar4;
  int iVar5;
  
  if (param_1 == 1) {
    iVar2 = zb_buf_get_out_func();
    if (iVar2 == 0) {
      uVar1 = esp_log_timestamp();
      esp_log_write(1,&_LC0,&_LC31,uVar1,&_LC0);
    }
    else {
      puVar3 = (undefined2 *)zb_buf_get_tail_func(0xc);
      iVar4 = parse_address(*param_2,puVar3 + 1,3);
      if (iVar4 == 0) {
        uVar1 = esp_log_timestamp();
        esp_log_write(1,&_LC0,&_LC36,uVar1,&_LC0);
      }
      else {
        iVar4 = get_free_ctx();
        if (iVar4 == 0) {
          uVar1 = esp_log_timestamp();
          esp_log_write(1,&_LC0,&_LC33,uVar1,&_LC0);
        }
        else {
          *puVar3 = 0xffff;
          *(undefined1 *)(puVar3 + 5) = 0;
          *(undefined1 *)((int)puVar3 + 0xb) = 0;
          iVar5 = zb_zdo_nwk_addr_req(iVar2,cmd_zb_nwk_addr_cb);
          *(char *)(iVar4 + 4) = (char)iVar5;
          if (iVar5 != 0xff) {
            iVar2 = zb_schedule_app_alarm(cmd_zb_nwk_addr_timeout,0x14a);
            if (iVar2 == 0) {
              return;
            }
            uVar1 = esp_log_timestamp();
            esp_log_write(1,&_LC0,&_LC38,uVar1,&_LC0);
            invalidate_ctx(iVar4);
            return;
          }
          uVar1 = esp_log_timestamp(0xff);
          esp_log_write(1,&_LC0,&_LC37,uVar1,&_LC0);
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
    esp_log_write(1,&_LC0,&_L0,uVar1,&_LC0);
  }
  return;
}

