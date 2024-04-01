/*
 * Last changed at upstream commit 3128a1de3a8a176dac99e12775a60287e9d10fd7
 * https://github.com/espressif/esp-zigbee-sdk/commit/3128a1de3a8a176dac99e12775a60287e9d10fd7
 * Upstream date: 2024-04-01 17:59:07 +0800
 * Upstream subject: esp-zigbee-sdk: release/v1.2.2(4a0e02cc)
 * Source: libesp_zb_api_zczr.debug -> esp_zigbee_aps.o -> zb_aps_data_indication_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int zb_aps_data_indication_handler(undefined4 param_1)

{
  byte *pbVar1;
  size_t __size;
  void *__dest;
  void *__src;
  int iVar2;
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
  
  pbVar1 = (byte *)zb_buf_get_tail_func(0x20);
  if (pbVar1 == (byte *)0x0) {
    iVar2 = 0;
  }
  else if (s_zb_apsde_data_ind_handler == (code *)0x0) {
    iVar2 = 0;
  }
  else {
    uStack_44 = uStack_44 & 0xffffff00;
    __size = zb_buf_len_func(param_1);
    sStack_34 = __size;
    __dest = malloc(__size);
    pvStack_30 = __dest;
    __src = (void *)zb_buf_begin_func(param_1);
    memcpy(__dest,__src,__size);
    uStack_44 = CONCAT22(*(undefined2 *)(pbVar1 + 3),(undefined2)uStack_44);
    uStack_40 = CONCAT31(uStack_40._1_3_,pbVar1[7]);
    uStack_40 = CONCAT22(*(undefined2 *)(pbVar1 + 1),(undefined2)uStack_40);
    uStack_3c = CONCAT31(uStack_3c._1_3_,pbVar1[8]);
    uStack_3c = CONCAT22(*(undefined2 *)(pbVar1 + 0xb),(undefined2)uStack_3c);
    uStack_38 = CONCAT22(uStack_38._2_2_,*(undefined2 *)(pbVar1 + 9));
    uStack_2c = CONCAT31(uStack_2c._1_3_,*pbVar1 >> 5) & 0xffffff01;
    uStack_64 = (uint)pbVar1[0x12];
    local_80 = uStack_44;
    uStack_7c = uStack_40;
    uStack_78 = uStack_3c;
    uStack_74 = uStack_38;
    sStack_70 = sStack_34;
    pvStack_6c = pvStack_30;
    uStack_68 = uStack_2c;
    uStack_60 = uStack_24;
    uStack_28 = uStack_64;
    iVar2 = (*s_zb_apsde_data_ind_handler)(&local_80,s_zb_apsde_data_ind_handler);
    free(__dest);
    if (iVar2 != 0) {
      zb_buf_free_func(param_1);
      zb_nwk_unlock_in(param_1);
    }
  }
  return iVar2;
}

