/*
 * Last changed at upstream commit 55d58f0243c7dca5c0887a2b065178dacc2d00be
 * https://github.com/espressif/esp-zigbee-sdk/commit/55d58f0243c7dca5c0887a2b065178dacc2d00be
 * Upstream date: 2022-11-15 14:25:21 +0800
 * Upstream subject: cli: Add cli example
 * Source: libesp_zb_cli_command -> zb_esp_cli_cmd_zdo.o -> cmd_zb_active_ep
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void cmd_zb_active_ep(int param_1,undefined4 *param_2)

{
  char *__s;
  undefined4 uVar1;
  int iVar2;
  undefined1 *puVar3;
  size_t sVar4;
  int iVar5;
  int iVar6;
  undefined1 auStack_12 [2];
  
  if (param_1 == 1) {
    iVar2 = zb_buf_get_out_func();
    if (iVar2 == 0) {
      uVar1 = esp_log_timestamp();
      esp_log_write(1,&_LC3,&_LC38,uVar1,&_LC3);
    }
    else {
      puVar3 = (undefined1 *)zb_buf_initial_alloc_func(2);
      __s = (char *)*param_2;
      sVar4 = strlen(__s);
      iVar5 = parse_hex_str(__s,sVar4 & 0xff,auStack_12,2,1);
      if (iVar5 == 0) {
        uVar1 = esp_log_timestamp();
        esp_log_write(1,&_LC3,&_LC57,uVar1,&_LC3);
      }
      else {
        *puVar3 = auStack_12[0];
        puVar3[1] = auStack_12[1];
        iVar5 = get_free_ctx();
        if (iVar5 == 0) {
          uVar1 = esp_log_timestamp();
          esp_log_write(1,&_LC3,&_LC40,uVar1,&_LC3);
        }
        else {
          iVar6 = zb_zdo_active_ep_req(iVar2,cmd_zb_active_ep_cb);
          *(char *)(iVar5 + 4) = (char)iVar6;
          if (iVar6 != 0xff) {
            return;
          }
          uVar1 = esp_log_timestamp();
          esp_log_write(1,&_LC3,&_LC58,uVar1,&_LC3);
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

