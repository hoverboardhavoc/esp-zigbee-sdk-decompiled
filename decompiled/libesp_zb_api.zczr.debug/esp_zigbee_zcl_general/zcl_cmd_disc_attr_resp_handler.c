/*
 * Last changed at upstream commit d4fdccd9eea771602c7571d5f751435deed089e9
 * https://github.com/espressif/esp-zigbee-sdk/commit/d4fdccd9eea771602c7571d5f751435deed089e9
 * Upstream date: 2025-05-21 11:16:30 +0000
 * Upstream subject: esp-zigbee-sdk: (5d895722)
 * Source: libesp_zb_api.zczr.debug -> esp_zigbee_zcl_general.o -> zcl_cmd_disc_attr_resp_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int zcl_cmd_disc_attr_resp_handler(undefined4 param_1)

{
  undefined2 *puVar1;
  undefined2 *puVar2;
  int iVar3;
  undefined1 *puVar4;
  undefined4 uVar5;
  uint uVar6;
  undefined2 *puVar7;
  undefined2 *puVar8;
  undefined1 auStack_38 [32];
  undefined1 uStack_18;
  undefined2 *puStack_14;
  
  uStack_18 = 0;
  puStack_14 = (undefined2 *)0x0;
  iVar3 = zb_zcl_basic_message_create(auStack_38);
  if (iVar3 == 0) {
    iVar3 = zb_buf_len_func(param_1);
    if (iVar3 == 0) {
      uStack_18 = 0;
    }
    else {
      puVar4 = (undefined1 *)zb_buf_begin_func(param_1);
      uStack_18 = *puVar4;
      zb_buf_cut_left_func(param_1,1);
    }
    puVar8 = (undefined2 *)0x0;
    do {
      uVar6 = zb_buf_len_func(param_1);
      puVar7 = puVar8;
      if (uVar6 < 3) {
        puVar2 = (undefined2 *)0x0;
_L0:
        puVar1 = puStack_14;
        if (puVar2 != (undefined2 *)0x0) {
          puVar7 = (undefined2 *)malloc(0xc);
          if (puVar7 == (undefined2 *)0x0) {
            uVar5 = esp_log_timestamp();
            esp_log_write(1,0x10000,&_LC6,uVar5,0x10000,"zcl_cmd_disc_attr_resp_handler",0xbc);
            return 0x101;
          }
          *puVar7 = *puVar2;
          *(uint *)(puVar7 + 2) = (uint)*(byte *)(puVar2 + 1);
          *(undefined4 *)(puVar7 + 4) = 0;
          puVar1 = puVar7;
          if (puVar8 != (undefined2 *)0x0) {
            *(undefined2 **)(puVar8 + 4) = puVar7;
            puVar1 = puStack_14;
          }
        }
      }
      else {
        puVar2 = (undefined2 *)zb_buf_begin_func(param_1);
        puVar1 = puStack_14;
        if (puVar2 != (undefined2 *)0x0) {
          zb_buf_cut_left_func(param_1,3);
          goto _L0;
        }
      }
      puStack_14 = puVar1;
      puVar8 = puVar7;
    } while (puVar2 != (undefined2 *)0x0);
    esp_zb_core_action_handler_schedule(0x1004,auStack_38);
    iVar3 = esp_err_to_zb_ret();
    puVar8 = puStack_14;
    while (puVar8 != (undefined2 *)0x0) {
      puVar7 = *(undefined2 **)(puVar8 + 4);
      free(puVar8);
      puVar8 = puVar7;
    }
  }
  else {
    uVar5 = esp_log_timestamp();
    esp_log_write(1,0x10000,&_L0,uVar5,0x10000,"zcl_cmd_disc_attr_resp_handler",0xb5);
  }
  return iVar3;
}

