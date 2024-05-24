/*
 * Last changed at upstream commit 9b2a25d84666d8bc8515f84abcf92271524d2896
 * https://github.com/espressif/esp-zigbee-sdk/commit/9b2a25d84666d8bc8515f84abcf92271524d2896
 * Upstream date: 2024-05-24 08:27:18 +0000
 * Upstream subject: esp-zigbee-lib:(73447d7e)
 * Source: libesp_zb_api_zczr.debug -> esp_zigbee_aps.o -> zb_aps_data_indication_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int zb_aps_data_indication_handler(undefined4 param_1)

{
  byte bVar1;
  short sVar2;
  byte *pbVar3;
  size_t __size;
  void *__dest;
  void *__src;
  int iVar4;
  undefined4 local_80;
  undefined4 uStack_7c;
  undefined4 uStack_78;
  undefined4 uStack_74;
  size_t sStack_70;
  void *pvStack_6c;
  uint uStack_68;
  uint uStack_64;
  undefined4 uStack_60;
  undefined4 uStack_44;
  undefined4 uStack_40;
  undefined4 uStack_3c;
  undefined4 uStack_38;
  size_t sStack_34;
  void *pvStack_30;
  uint uStack_2c;
  uint uStack_28;
  undefined4 uStack_24;
  
  pbVar3 = (byte *)zb_buf_get_tail_func(0x20);
  if (pbVar3 == (byte *)0x0) {
    iVar4 = 0;
  }
  else if (s_zb_apsde_data_ind_handler == (code *)0x0) {
    iVar4 = 0;
  }
  else {
    uStack_44 = uStack_44 & 0xffffff00;
    __size = zb_buf_len_func(param_1);
    sStack_34 = __size;
    __dest = malloc(__size);
    pvStack_30 = __dest;
    __src = (void *)zb_buf_begin_func(param_1);
    memcpy(__dest,__src,__size);
    sVar2 = *(short *)(pbVar3 + 3);
    bVar1 = pbVar3[7];
    uStack_40 = CONCAT31(uStack_40._1_3_,bVar1);
    uStack_40 = CONCAT22(*(undefined2 *)(pbVar3 + 1),(undefined2)uStack_40);
    uStack_3c = CONCAT31(uStack_3c._1_3_,pbVar3[8]);
    uStack_3c = CONCAT22(*(undefined2 *)(pbVar3 + 0xb),(undefined2)uStack_3c);
    uStack_38 = CONCAT22(uStack_38._2_2_,*(undefined2 *)(pbVar3 + 9));
    uStack_2c = CONCAT31(uStack_2c._1_3_,*pbVar3 >> 5) & 0xffffff01;
    uStack_64 = (uint)pbVar3[0x12];
    uStack_24 = 0;
    if ((*(short *)(pbVar3 + 5) == 0) || (bVar1 != 0)) {
      if ((sVar2 == 0) || (bVar1 == 0)) {
        uStack_44._0_2_ = CONCAT11(0xff,(undefined1)uStack_44);
        uStack_44 = CONCAT22(sVar2,(undefined2)uStack_44);
      }
      else {
        uStack_44._0_2_ = CONCAT11(2,(undefined1)uStack_44);
        uStack_44 = CONCAT22(sVar2,(undefined2)uStack_44);
      }
    }
    else {
      uStack_44._0_2_ = CONCAT11(1,(undefined1)uStack_44);
      uStack_44 = CONCAT22(*(short *)(pbVar3 + 5),(undefined2)uStack_44);
    }
    local_80 = uStack_44;
    uStack_7c = uStack_40;
    uStack_78 = uStack_3c;
    uStack_74 = uStack_38;
    sStack_70 = sStack_34;
    pvStack_6c = pvStack_30;
    uStack_68 = uStack_2c;
    uStack_60 = 0;
    uStack_28 = uStack_64;
    iVar4 = (*s_zb_apsde_data_ind_handler)(&local_80,s_zb_apsde_data_ind_handler);
    free(__dest);
    if (iVar4 != 0) {
      zb_buf_free_func(param_1);
      zb_nwk_unlock_in(param_1);
    }
  }
  return iVar4;
}

