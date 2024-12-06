/*
 * Last changed at upstream commit 0bff9367811bb8cb2d99200afddf6ceefe2628f8
 * https://github.com/espressif/esp-zigbee-sdk/commit/0bff9367811bb8cb2d99200afddf6ceefe2628f8
 * Upstream date: 2024-12-06 13:11:49 +0800
 * Upstream subject: esp-zigbee-sdk: (e9475ff2)
 * Source: libesp_zb_api.zczr -> esp_zigbee_nwk.o -> esp_zb_nwk_get_next_neighbor
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 esp_zb_nwk_get_next_neighbor(ushort *param_1,int param_2)

{
  byte bVar1;
  byte *pbVar2;
  uint uVar3;
  undefined2 uVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  int extraout_a1;
  int extraout_a1_00;
  int extraout_a1_01;
  undefined4 uVar8;
  byte *apbStack_24 [2];
  
  apbStack_24[0] = (byte *)0x0;
  uVar8 = 0x102;
  if (param_2 != 0) {
    uVar3 = (uint)*param_1;
    if (uVar3 != 0xffff) {
      for (; uVar3 < _gc_neighbor_table_size; uVar3 = uVar3 + 1 & 0xffff) {
        iVar5 = zb_nwk_neighbor_get_by_idx(uVar3 & 0xff,apbStack_24);
        pbVar2 = apbStack_24[0];
        if (((iVar5 == 0) && ((*apbStack_24[0] & 2) == 0)) &&
           (((*apbStack_24[0] & 0xc) == 8 || ((apbStack_24[0][8] & 0x70) != 0)))) {
          *param_1 = (ushort)(uVar3 + 1);
          zb_address_ieee_by_ref(param_2,apbStack_24[0][7]);
          uVar4 = zb_address_short_by_ieee(param_2);
          bVar1 = *pbVar2;
          *(undefined2 *)(param_2 + 8) = uVar4;
          *(byte *)(param_2 + 10) = bVar1 >> 2 & 3;
          *(byte *)(param_2 + 0xb) = *pbVar2 >> 4;
          *(byte *)(param_2 + 0xc) = pbVar2[1] >> 1 & 1;
          *(byte *)(param_2 + 0xd) = pbVar2[1] >> 2 & 7;
          *(byte *)(param_2 + 0xe) = pbVar2[4];
          *(byte *)(param_2 + 0xf) = pbVar2[5];
          *(byte *)(param_2 + 0x10) = pbVar2[8] >> 4 & 7;
          *(byte *)(param_2 + 0x11) = (byte)((pbVar2[9] & 0xf) << 1) | pbVar2[8] >> 7;
          uVar8 = zb_convert_timeout_value(pbVar2[8] & 0xf);
          *(undefined4 *)(param_2 + 0x14) = uVar8;
          uVar3 = *(uint *)(pbVar2 + 0xe);
          iVar5 = *(int *)(pbVar2 + 0x12);
          iVar6 = zb_timer_get();
          uVar7 = uVar3 - iVar6;
          uVar3 = (iVar5 - extraout_a1) - (uint)(uVar3 < uVar7);
          if ((uVar3 < 0x80000000) && ((uVar3 != 0x7fffffff || (uVar7 < 0xffffffff)))) {
            uVar3 = *(uint *)(pbVar2 + 0xe);
            iVar5 = *(int *)(pbVar2 + 0x12);
            iVar6 = zb_timer_get();
            iVar5 = (iVar5 - extraout_a1_00) - (uint)(uVar3 < uVar3 - iVar6);
          }
          else {
            uVar3 = zb_timer_get();
            iVar5 = (extraout_a1_01 - *(int *)(pbVar2 + 0x12)) -
                    (uint)(uVar3 < uVar3 - *(int *)(pbVar2 + 0xe));
          }
          uVar8 = __udivdi3(iVar5,1000,0);
          *(undefined4 *)(param_2 + 0x18) = uVar8;
          return 0;
        }
      }
      *param_1 = 0xffff;
    }
    uVar8 = 0x105;
  }
  return uVar8;
}

