/*
 * Last changed at upstream commit 790bc8d6ece1bf5f739debaa4aa4af508982070a
 * https://github.com/espressif/esp-zigbee-sdk/commit/790bc8d6ece1bf5f739debaa4aa4af508982070a
 * Upstream date: 2023-12-21 19:52:25 +0800
 * Upstream subject: esp-zigbee-sdk: release/v1.0.7(bdde218a)
 * Source: libesp_zb_cli_command -> zb_esp_cli_cmd_zdo.o -> cmd_zb_simple_desc_req_cb
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void cmd_zb_simple_desc_req_cb(undefined4 param_1)

{
  byte bVar1;
  byte bVar2;
  byte bVar3;
  undefined1 *puVar4;
  int iVar5;
  undefined4 uVar6;
  uint uVar7;
  char cStack_95;
  undefined4 uStack_94;
  char acStack_90 [8];
  undefined2 uStack_88;
  
  puVar4 = (undefined1 *)zb_buf_begin_func();
  bVar2 = puVar4[0xb];
  bVar1 = puVar4[0xc];
  memset(&uStack_94,0,100);
  iVar5 = get_ctx_by_tsn(*puVar4);
  if (iVar5 == 0) {
    zb_buf_free_func(param_1);
  }
  else {
    if (puVar4[1] == '\0') {
      uVar6 = esp_log_timestamp();
      esp_log_write(3,&_LC0,&_LC25,uVar6,&_LC0,*(undefined2 *)(puVar4 + 2),puVar4[5],
                    *(undefined2 *)(puVar4 + 6));
      uStack_94._0_1_ = 'i';
      uStack_94._1_1_ = 'n';
      uStack_94._2_1_ = ' ';
      uStack_94._3_1_ = 'c';
      builtin_strncpy(acStack_90,"lusters=",8);
      uStack_88 = (ushort)uStack_88._1_1_ << 8;
      uVar7 = 0xc;
      for (bVar3 = 0; bVar3 < bVar2; bVar3 = bVar3 + 1) {
        sprintf((char *)((int)&uStack_94 + uVar7),"0x%04x,");
        uVar7 = uVar7 + 7 & 0xff;
      }
      (&cStack_95)[uVar7] = '\0';
      uVar6 = esp_log_timestamp();
      esp_log_write(3,&_LC0,&_LC19,uVar6,&_LC0,&uStack_94);
      memset(&uStack_94,0,100);
      uStack_94._0_1_ = 'o';
      uStack_94._1_1_ = 'u';
      uStack_94._2_1_ = 't';
      uStack_94._3_1_ = ' ';
      builtin_strncpy(acStack_90,"clusters",8);
      uStack_88._0_1_ = '=';
      uStack_88._1_1_ = '\0';
      uVar7 = 0xd;
      for (bVar2 = 0; bVar2 < bVar1; bVar2 = bVar2 + 1) {
        sprintf((char *)((int)&uStack_94 + uVar7),"0x%04x,");
        uVar7 = uVar7 + 7 & 0xff;
      }
      (&cStack_95)[uVar7] = '\0';
      uVar6 = esp_log_timestamp();
      esp_log_write(3,&_LC0,&_LC19,uVar6,&_LC0,&uStack_94);
      uVar6 = esp_log_timestamp();
      esp_log_write(3,&_LC0,&_LC4,uVar6,&_LC0);
    }
    else {
      uVar6 = esp_log_timestamp();
      esp_log_write(3,&_LC0,&_LC29,uVar6,&_LC0);
    }
    invalidate_ctx(iVar5);
    zb_buf_free_func(param_1);
  }
  return;
}

