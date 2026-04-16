/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> buffer.o -> zmsg_remove_header
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Type propagation algorithm not settling */

void zmsg_remove_header(zmsg_t *msg,uint16_t length)

{
  ushort uVar1;
  ushort uVar2;
  buffer_t *pbVar3;
  buffer_t *pbVar4;
  buffer_t *pbVar5;
  buffer_t *pbVar6;
  buffer_t *pbVar7;
  int extraout_a1;
  int extraout_a1_00;
  int iVar8;
  int extraout_a1_01;
  undefined4 *puVar9;
  uint __n;
  undefined4 *puVar10;
  uint uVar11;
  
  pbVar6 = (buffer_t *)__assert_func(0,0,0,0);
  uVar1 = *(ushort *)((int)pbVar6->data + 8);
  uVar2 = *(ushort *)((int)pbVar6->data + 0xc);
  pbVar4 = (buffer_t *)((int)pbVar6->data + 4);
  uVar11 = 0;
  pbVar5 = pbVar4;
  pbVar7 = pbVar6;
  iVar8 = extraout_a1;
  do {
    if ((extraout_a1 + (uint)uVar1 + (uint)uVar2 & 0xffff) <= uVar11) {
      pbVar3 = pbVar4;
      if (pbVar4 == pbVar5) {
        do {
          pbVar5 = pbVar3;
          pbVar3 = *(buffer_t **)&pbVar5->field_0;
        } while (*(buffer_t **)&pbVar5->field_0 != (buffer_t *)0x0);
      }
      __n = (uint)*(ushort *)((int)pbVar6->data + 0xc);
      if (__n == 0) goto _L0;
      if (__n < 0xad) {
        memmove((uint8_t *)((0xb0 - __n) + (int)pbVar4),(uint8_t *)((int)pbVar5 + (0xb0 - __n)),__n)
        ;
_L0:
        puVar9 = *(undefined4 **)&pbVar4->field_0;
        while (puVar9 != (undefined4 *)0x0) {
          puVar10 = (undefined4 *)*puVar9;
          *puVar9 = 0;
          mempool_free(0);
          puVar9 = puVar10;
        }
        pbVar4->field_0 = (anon_union_4_2_77b2d3ce_for_buffer_s_0)0x0;
        return;
      }
      buffer_get_tail(pbVar7,(uint16_t)iVar8);
      iVar8 = extraout_a1_00;
    }
    if (*(buffer_t **)&pbVar4->field_0 == (buffer_t *)0x0) {
      pbVar7 = (buffer_t *)mempool_malloc();
      pbVar4->field_0 = (anon_union_4_2_77b2d3ce_for_buffer_s_0)pbVar7;
      iVar8 = extraout_a1_01;
      if (pbVar7 == (buffer_t *)0x0) goto _L0;
    }
    else {
      pbVar5 = *(buffer_t **)&pbVar5->field_0;
      pbVar7 = *(buffer_t **)&pbVar4->field_0;
    }
    pbVar4 = pbVar7;
    uVar11 = uVar11 + 0xac & 0xffff;
    pbVar7 = pbVar4;
  } while( true );
}

