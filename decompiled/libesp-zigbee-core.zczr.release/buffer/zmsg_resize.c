/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> buffer.o -> zmsg_resize
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Type propagation algorithm not settling */
/* WARNING: Unknown calling convention */

ezb_err_t zmsg_resize(zmsg_t *msg,uint16_t length)

{
  buffer_t *pbVar1;
  buffer_t *pbVar2;
  ezb_err_t eVar3;
  buffer_t *pbVar4;
  buffer_t *pbVar5;
  uint uVar6;
  uint extraout_a1;
  uint extraout_a1_00;
  undefined4 *puVar7;
  uint __n;
  undefined4 *puVar8;
  uint uVar9;
  uint uVar10;
  
  uVar6 = (uint)length;
  uVar9 = uVar6 + (uint)msg->header + (uint)msg->tail;
  pbVar2 = (buffer_t *)&msg->chunks;
  uVar10 = 0;
  pbVar4 = pbVar2;
  pbVar5 = (buffer_t *)msg;
  do {
    if ((uVar9 & 0xffff) <= uVar10) {
      pbVar1 = pbVar2;
      if (pbVar2 == pbVar4) {
        do {
          pbVar4 = pbVar1;
          pbVar1 = *(buffer_t **)&pbVar4->field_0;
        } while (*(buffer_t **)&pbVar4->field_0 != (buffer_t *)0x0);
      }
      __n = (uint)msg->tail;
      if (__n != 0) {
        if (0xac < __n) {
          buffer_get_tail(pbVar5,(uint16_t)uVar6);
          uVar6 = extraout_a1;
          goto _L0;
        }
        memmove((void *)((0xb0 - __n) + (int)pbVar2),(void *)((int)pbVar4 + (0xb0 - __n)),__n);
      }
      eVar3 = 0;
      goto _L0;
    }
_L0:
    if (*(buffer_t **)&pbVar2->field_0 == (buffer_t *)0x0) {
      pbVar5 = (buffer_t *)mempool_malloc();
      pbVar2->field_0 = (anon_union_4_2_77b2d3ce_for_buffer_s_0)pbVar5;
      uVar6 = extraout_a1_00;
      if (pbVar5 == (buffer_t *)0x0) {
        eVar3 = 1;
_L0:
        puVar7 = *(undefined4 **)&pbVar2->field_0;
        while (puVar7 != (undefined4 *)0x0) {
          puVar8 = (undefined4 *)*puVar7;
          *puVar7 = 0;
          mempool_free(0);
          puVar7 = puVar8;
        }
        pbVar2->field_0 = (anon_union_4_2_77b2d3ce_for_buffer_s_0)0x0;
        return eVar3;
      }
    }
    else {
      pbVar4 = *(buffer_t **)&pbVar4->field_0;
      pbVar5 = *(buffer_t **)&pbVar2->field_0;
    }
    pbVar2 = pbVar5;
    uVar10 = uVar10 + 0xac & 0xffff;
    pbVar5 = pbVar2;
  } while( true );
}

