/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> buffer.o -> buffer_get_tail
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Type propagation algorithm not settling */

uint8_t * buffer_get_tail(buffer_t *buf,uint16_t tail_size)

{
  ushort uVar1;
  ushort uVar2;
  buffer_t *pbVar3;
  buffer_t *pbVar4;
  uint8_t *puVar5;
  buffer_t *pbVar6;
  buffer_t *pbVar7;
  buffer_t *pbVar8;
  int extraout_a1;
  int extraout_a1_00;
  int iVar9;
  int extraout_a1_01;
  undefined4 *puVar10;
  uint __n;
  undefined4 *puVar11;
  uint uVar12;
  
  __assert_func(0,0,0,0);
  pbVar7 = (buffer_t *)__assert_func(0,0,0,0);
  uVar1 = *(ushort *)((int)pbVar7->data + 8);
  uVar2 = *(ushort *)((int)pbVar7->data + 0xc);
  pbVar4 = (buffer_t *)((int)pbVar7->data + 4);
  uVar12 = 0;
  pbVar6 = pbVar4;
  pbVar8 = pbVar7;
  iVar9 = extraout_a1;
  do {
    if ((extraout_a1 + (uint)uVar1 + (uint)uVar2 & 0xffff) <= uVar12) {
      pbVar3 = pbVar4;
      if (pbVar4 == pbVar6) {
        do {
          pbVar6 = pbVar3;
          pbVar3 = *(buffer_t **)&pbVar6->field_0;
        } while (*(buffer_t **)&pbVar6->field_0 != (buffer_t *)0x0);
      }
      __n = (uint)*(ushort *)((int)pbVar7->data + 0xc);
      if (__n != 0) {
        if (0xac < __n) {
          buffer_get_tail(pbVar8,(uint16_t)iVar9);
          iVar9 = extraout_a1_00;
          goto _L0;
        }
        memmove((uint8_t *)((0xb0 - __n) + (int)pbVar4),(uint8_t *)((int)pbVar6 + (0xb0 - __n)),__n)
        ;
      }
      puVar5 = (uint8_t *)0x0;
      goto _L0;
    }
_L0:
    if (*(buffer_t **)&pbVar4->field_0 == (buffer_t *)0x0) {
      pbVar8 = (buffer_t *)mempool_malloc();
      pbVar4->field_0 = (anon_union_4_2_77b2d3ce_for_buffer_s_0)pbVar8;
      iVar9 = extraout_a1_01;
      if (pbVar8 == (buffer_t *)0x0) {
        puVar5 = (uint8_t *)0x1;
_L0:
        puVar10 = *(undefined4 **)&pbVar4->field_0;
        while (puVar10 != (undefined4 *)0x0) {
          puVar11 = (undefined4 *)*puVar10;
          *puVar10 = 0;
          mempool_free(0);
          puVar10 = puVar11;
        }
        pbVar4->field_0 = (anon_union_4_2_77b2d3ce_for_buffer_s_0)0x0;
        return puVar5;
      }
    }
    else {
      pbVar6 = *(buffer_t **)&pbVar6->field_0;
      pbVar8 = *(buffer_t **)&pbVar4->field_0;
    }
    pbVar4 = pbVar8;
    uVar12 = uVar12 + 0xac & 0xffff;
    pbVar8 = pbVar4;
  } while( true );
}

