/*
 * Last changed at upstream commit c1113e88ee047f0eb31a91352a6fd0fc5318b6fd
 * https://github.com/espressif/esp-zigbee-sdk/commit/c1113e88ee047f0eb31a91352a6fd0fc5318b6fd
 * Upstream date: 2023-08-30 15:00:29 +0800
 * Upstream subject: esp-zigbee-sdk: release/v0.9.3(6da46788)
 * Source: libesp_zb_api_zczr -> esp_zigbee_core.o -> zb_zcl_basic_message_create
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
    uVar10 = 0xffffffff;
  }
  else {
    *param_1 = 0;
    uVar1 = puVar9[1];
    uVar2 = puVar9[2];
    uVar3 = puVar9[3];
    uVar4 = puVar9[4];
    uVar5 = puVar9[5];
    uVar6 = puVar9[6];
    uVar7 = puVar9[7];
    uVar8 = puVar9[8];
    *(undefined1 *)(param_1 + 1) = *puVar9;
    *(undefined1 *)((int)param_1 + 5) = uVar1;
    *(undefined1 *)((int)param_1 + 6) = uVar2;
    *(undefined1 *)((int)param_1 + 7) = uVar3;
    *(undefined1 *)(param_1 + 2) = uVar4;
    *(undefined1 *)((int)param_1 + 9) = uVar5;
    *(undefined1 *)((int)param_1 + 10) = uVar6;
    *(undefined1 *)((int)param_1 + 0xb) = uVar7;
    *(undefined1 *)(param_1 + 3) = uVar8;
    *(undefined2 *)((int)param_1 + 0xe) = *(undefined2 *)(puVar9 + 9);
    *(undefined1 *)(param_1 + 4) = puVar9[0xb];
    *(undefined1 *)((int)param_1 + 0x11) = puVar9[0xc];
    *(undefined2 *)((int)param_1 + 0x12) = *(undefined2 *)(puVar9 + 0xf);
    *(undefined2 *)(param_1 + 5) = *(undefined2 *)(puVar9 + 0x11);
    *(undefined1 *)((int)param_1 + 0x17) = puVar9[0x14];
    *(undefined1 *)(param_1 + 6) = puVar9[0x16];
    *(undefined1 *)((int)param_1 + 0x16) = puVar9[0x13];
    uVar10 = 0;
  }
  return uVar10;
}

