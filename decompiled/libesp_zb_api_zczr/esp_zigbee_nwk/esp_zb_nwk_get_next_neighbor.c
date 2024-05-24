/*
 * Last changed at upstream commit 9b2a25d84666d8bc8515f84abcf92271524d2896
 * https://github.com/espressif/esp-zigbee-sdk/commit/9b2a25d84666d8bc8515f84abcf92271524d2896
 * Upstream date: 2024-05-24 08:27:18 +0000
 * Upstream subject: esp-zigbee-lib:(73447d7e)
 * Source: libesp_zb_api_zczr -> esp_zigbee_nwk.o -> esp_zb_nwk_get_next_neighbor
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 esp_zb_nwk_get_next_neighbor(ushort *param_1,int param_2)

{
  byte *pbVar1;
  uint uVar2;
  undefined2 uVar3;
  int iVar4;
  undefined4 uVar5;
  int iVar6;
  uint uVar7;
  int extraout_a1;
  int extraout_a1_00;
  int extraout_a1_01;
  byte bVar8;
  byte *apbStack_24 [2];
  
  uVar2 = (uint)*param_1;
  apbStack_24[0] = (byte *)0x0;
  if (uVar2 != 0xffff) {
    for (; uVar2 < _gc_neighbor_table_size; uVar2 = uVar2 + 1 & 0xffff) {
      iVar4 = zb_nwk_neighbor_get_by_idx(uVar2 & 0xff,apbStack_24);
      pbVar1 = apbStack_24[0];
      if (((iVar4 == 0) && ((*apbStack_24[0] & 2) == 0)) &&
         (((*apbStack_24[0] & 0xc) == 8 || ((apbStack_24[0][8] & 0x70) != 0)))) {
        *param_1 = (ushort)(uVar2 + 1);
        zb_address_ieee_by_ref(param_2,apbStack_24[0][7]);
        uVar3 = zb_address_short_by_ieee(param_2);
        bVar8 = *pbVar1;
        *(undefined2 *)(param_2 + 8) = uVar3;
        *(byte *)(param_2 + 10) = bVar8 >> 2 & 3;
        *(byte *)(param_2 + 0xb) = *pbVar1 >> 4;
        *(byte *)(param_2 + 0xc) = pbVar1[1] >> 1 & 1;
        bVar8 = pbVar1[1] >> 2 & 7;
        if (3 < bVar8) {
          bVar8 = 3;
        }
        *(byte *)(param_2 + 0xd) = bVar8;
        *(byte *)(param_2 + 0xe) = pbVar1[4];
        *(byte *)(param_2 + 0xf) = pbVar1[5];
        *(byte *)(param_2 + 0x10) = pbVar1[8] >> 4 & 7;
        *(byte *)(param_2 + 0x11) = (byte)((pbVar1[9] & 0xf) << 1) | pbVar1[8] >> 7;
        uVar5 = zb_convert_timeout_value(pbVar1[8] & 0xf);
        *(undefined4 *)(param_2 + 0x14) = uVar5;
        uVar2 = *(uint *)(pbVar1 + 0xe);
        iVar4 = *(int *)(pbVar1 + 0x12);
        iVar6 = zb_timer_get();
        uVar7 = uVar2 - iVar6;
        uVar2 = (iVar4 - extraout_a1) - (uint)(uVar2 < uVar7);
        if ((uVar2 < 0x80000000) && ((uVar2 != 0x7fffffff || (uVar7 < 0xffffffff)))) {
          uVar2 = *(uint *)(pbVar1 + 0xe);
          iVar4 = *(int *)(pbVar1 + 0x12);
          iVar6 = zb_timer_get();
          iVar4 = (iVar4 - extraout_a1_00) - (uint)(uVar2 < uVar2 - iVar6);
        }
        else {
          uVar2 = zb_timer_get();
          iVar4 = (extraout_a1_01 - *(int *)(pbVar1 + 0x12)) -
                  (uint)(uVar2 < uVar2 - *(int *)(pbVar1 + 0xe));
        }
        uVar5 = __udivdi3(iVar4,1000,0);
        *(undefined4 *)(param_2 + 0x18) = uVar5;
        return 0;
      }
    }
    *param_1 = 0xffff;
  }
  return 0x105;
}

