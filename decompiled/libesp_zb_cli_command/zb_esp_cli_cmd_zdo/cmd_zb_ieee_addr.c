/*
 * Last changed at upstream commit 55d58f0243c7dca5c0887a2b065178dacc2d00be
 * https://github.com/espressif/esp-zigbee-sdk/commit/55d58f0243c7dca5c0887a2b065178dacc2d00be
 * Upstream date: 2022-11-15 14:25:21 +0800
 * Upstream subject: cli: Add cli example
 * Source: libesp_zb_cli_command -> zb_esp_cli_cmd_zdo.o -> cmd_zb_ieee_addr
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void cmd_zb_ieee_addr(int param_1,undefined4 *param_2)

{
  char *__s;
  undefined4 uVar1;
  int iVar2;
  undefined2 *puVar3;
  size_t sVar4;
  int iVar5;
  int iVar6;
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
      __s = (char *)*param_2;
      sVar4 = strlen(__s);
      iVar5 = parse_hex_str(__s,sVar4 & 0xff,&uStack_12,2,1);
      if (iVar5 == 0) {
        uVar1 = esp_log_timestamp();
        esp_log_write(1,&_LC3,&_LC57,uVar1,&_LC3);
      }
      else {
        puVar3[1] = uStack_12;
        *puVar3 = uStack_12;
        iVar5 = get_free_ctx();
        if (iVar5 == 0) {
          uVar1 = esp_log_timestamp();
          esp_log_write(1,&_LC3,&_LC40,uVar1,&_LC3);
        }
        else {
          iVar6 = zb_zdo_ieee_addr_req(iVar2,cmd_zb_ieee_addr_cb);
          *(char *)(iVar5 + 4) = (char)iVar6;
          if (iVar6 != 0xff) {
            iVar2 = zb_schedule_app_alarm(cmd_zb_ieee_addr_timeout,0x14a);
            if (iVar2 == 0) {
              return;
            }
            uVar1 = esp_log_timestamp();
            esp_log_write(1,&_LC3,&_LC42,uVar1,&_LC3);
            invalidate_ctx(iVar5);
            return;
          }
          uVar1 = esp_log_timestamp(0xff);
          esp_log_write(1,&_LC3,&_LC41,uVar1,&_LC3);
        }
        if (iVar5 != 0) {
          invalidate_ctx(iVar5);
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

