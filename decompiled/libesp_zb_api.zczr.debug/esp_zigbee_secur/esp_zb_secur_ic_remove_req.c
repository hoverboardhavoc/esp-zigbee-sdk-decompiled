/*
 * Last changed at upstream commit 0bff9367811bb8cb2d99200afddf6ceefe2628f8
 * https://github.com/espressif/esp-zigbee-sdk/commit/0bff9367811bb8cb2d99200afddf6ceefe2628f8
 * Upstream date: 2024-12-06 13:11:49 +0800
 * Upstream subject: esp-zigbee-sdk: (e9475ff2)
 * Source: libesp_zb_api.zczr.debug -> esp_zigbee_secur.o -> esp_zb_secur_ic_remove_req
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 esp_zb_secur_ic_remove_req(undefined1 *param_1)

{
  undefined1 uVar1;
  undefined1 uVar2;
  undefined1 uVar3;
  undefined1 uVar4;
  undefined1 uVar5;
  undefined1 uVar6;
  undefined1 uVar7;
  undefined4 uVar8;
  undefined1 *puVar9;
  
  uVar8 = zb_buf_get_out_func();
  puVar9 = (undefined1 *)zb_buf_get_tail_func(0xc);
  uVar1 = param_1[1];
  uVar2 = param_1[2];
  uVar3 = param_1[3];
  uVar4 = param_1[4];
  uVar5 = param_1[5];
  uVar6 = param_1[6];
  uVar7 = param_1[7];
  *puVar9 = *param_1;
  puVar9[1] = uVar1;
  puVar9[2] = uVar2;
  puVar9[3] = uVar3;
  puVar9[4] = uVar4;
  puVar9[5] = uVar5;
  puVar9[6] = uVar6;
  puVar9[7] = uVar7;
  puVar9[8] = 0x2c;
  puVar9[9] = 0;
  puVar9[10] = 1;
  puVar9[0xb] = 0;
  zb_secur_ic_remove_req(uVar8);
  return ic_remove_cb_ret;
}

