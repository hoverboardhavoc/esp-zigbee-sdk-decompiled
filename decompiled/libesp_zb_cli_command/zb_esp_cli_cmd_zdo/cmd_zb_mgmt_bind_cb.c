/*
 * Last changed at upstream commit 55d58f0243c7dca5c0887a2b065178dacc2d00be
 * https://github.com/espressif/esp-zigbee-sdk/commit/55d58f0243c7dca5c0887a2b065178dacc2d00be
 * Upstream date: 2022-11-15 14:25:21 +0800
 * Upstream subject: cli: Add cli example
 * Source: libesp_zb_cli_command -> zb_esp_cli_cmd_zdo.o -> cmd_zb_mgmt_bind_cb
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void cmd_zb_mgmt_bind_cb(int param_1)

{
  byte bVar1;
  byte bVar2;
  undefined1 *puVar3;
  int iVar4;
  undefined4 uVar5;
  char *pcVar6;
  int iVar7;
  uint uVar8;
  
  puVar3 = (undefined1 *)zb_buf_begin_func();
  iVar4 = get_ctx_by_tsn(*puVar3);
  if (iVar4 != 0) {
    if (puVar3[1] == '\0') {
      if (puVar3[3] == *(char *)(iVar4 + 8)) {
        uVar5 = esp_log_timestamp();
        esp_log_write(3,&_LC3,&_LC45,uVar5,&_LC3);
      }
      print_bind_resp(puVar3);
      bVar1 = puVar3[3];
      bVar2 = puVar3[4];
      uVar8 = (uint)bVar2 + (uint)bVar1;
      if (((uVar8 < (byte)puVar3[2]) && (uVar8 < 0xff)) && (bVar2 != 0)) {
        zb_buf_reuse_func(param_1);
        pcVar6 = (char *)zb_buf_get_tail_func(param_1,4);
        *(undefined2 *)(pcVar6 + 2) = *(undefined2 *)(iVar4 + 10);
        *pcVar6 = bVar1 + bVar2;
        iVar7 = zb_zdo_mgmt_bind_req(param_1,cmd_zb_mgmt_bind_cb);
        *(char *)(iVar4 + 4) = (char)iVar7;
        if (iVar7 != 0xff) {
          iVar4 = 0;
          goto _L0;
        }
        uVar5 = esp_log_timestamp();
        esp_log_write(1,&_LC3,&_LC41,uVar5,&_LC3);
      }
      else {
        uVar5 = esp_log_timestamp();
        esp_log_write(3,&_LC3,&_LC46,uVar5,&_LC3,puVar3[2]);
        uVar5 = esp_log_timestamp();
        esp_log_write(3,&_LC3,&_LC7,uVar5,&_LC3);
      }
    }
    else {
      uVar5 = esp_log_timestamp();
      esp_log_write(1,&_LC3,&_LC47,uVar5,&_LC3);
    }
  }
  if (param_1 != 0) {
    zb_buf_free_func(param_1);
  }
_L0:
  if (iVar4 != 0) {
    invalidate_ctx(iVar4);
  }
  return;
}

