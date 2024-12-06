/*
 * Last changed at upstream commit 0bff9367811bb8cb2d99200afddf6ceefe2628f8
 * https://github.com/espressif/esp-zigbee-sdk/commit/0bff9367811bb8cb2d99200afddf6ceefe2628f8
 * Upstream date: 2024-12-06 13:11:49 +0800
 * Upstream subject: esp-zigbee-sdk: (e9475ff2)
 * Source: libesp_zb_api.zczr.debug -> esp_zigbee_core.o -> zb_zcl_basic_message_create
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 zb_zcl_basic_message_create(undefined4 *param_1)

{
  undefined1 uVar1;
  undefined1 uVar2;
  undefined1 uVar3;
  undefined1 uVar4;
  undefined1 uVar5;
  undefined1 uVar6;
  undefined1 uVar7;
  undefined1 uVar8;
  undefined1 *puVar9;
  undefined4 uVar10;
  
  puVar9 = (undefined1 *)zb_buf_get_tail_func(0x1b);
  if (puVar9 == (undefined1 *)0x0) {
    *param_1 = 1;
    uVar10 = 0xffffffff;
  }
  else {
    *param_1 = 0;
    *(undefined1 *)(param_1 + 1) = puVar9[0xd];
    *(undefined2 *)((int)param_1 + 6) = *(undefined2 *)(puVar9 + 0x19);
    *(undefined1 *)(param_1 + 2) = puVar9[0x15];
    *(undefined1 *)((int)param_1 + 9) = puVar9[0xe];
    uVar1 = puVar9[1];
    uVar2 = puVar9[2];
    uVar3 = puVar9[3];
    uVar4 = puVar9[4];
    uVar5 = puVar9[5];
    uVar6 = puVar9[6];
    uVar7 = puVar9[7];
    uVar8 = puVar9[8];
    *(undefined1 *)((int)param_1 + 10) = *puVar9;
    *(undefined1 *)((int)param_1 + 0xb) = uVar1;
    *(undefined1 *)(param_1 + 3) = uVar2;
    *(undefined1 *)((int)param_1 + 0xd) = uVar3;
    *(undefined1 *)((int)param_1 + 0xe) = uVar4;
    *(undefined1 *)((int)param_1 + 0xf) = uVar5;
    *(undefined1 *)(param_1 + 4) = uVar6;
    *(undefined1 *)((int)param_1 + 0x11) = uVar7;
    *(undefined1 *)((int)param_1 + 0x12) = uVar8;
    *(undefined2 *)(param_1 + 5) = *(undefined2 *)(puVar9 + 9);
    *(undefined1 *)((int)param_1 + 0x16) = puVar9[0xb];
    *(undefined1 *)((int)param_1 + 0x17) = puVar9[0xc];
    *(undefined2 *)(param_1 + 6) = *(undefined2 *)(puVar9 + 0xf);
    *(undefined2 *)((int)param_1 + 0x1a) = *(undefined2 *)(puVar9 + 0x11);
    *(undefined1 *)((int)param_1 + 0x1d) = puVar9[0x14];
    *(undefined1 *)((int)param_1 + 0x1e) = puVar9[0x16];
    *(undefined1 *)(param_1 + 7) = puVar9[0x13];
    uVar10 = 0;
  }
  return uVar10;
}

