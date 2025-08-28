/*
 * Last changed at upstream commit 88dfcd2f3748e37cbfac85eea52d0fdfbe99049b
 * https://github.com/espressif/esp-zigbee-sdk/commit/88dfcd2f3748e37cbfac85eea52d0fdfbe99049b
 * Upstream date: 2025-08-28 11:19:03 +0000
 * Upstream subject: esp-zigbee-sdk: (0166821f)
 * Source: libesp_zb_api.zczr -> esp_zigbee_zcl_scenes.o -> zb_nvram_app1_write_cb
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 zb_nvram_app1_write_cb(undefined4 param_1,undefined4 param_2)

{
  byte bVar1;
  undefined4 uVar2;
  uint uVar3;
  size_t __size;
  short *__s;
  uint uVar4;
  void *__src;
  undefined1 *puVar5;
  int iVar6;
  
  __size = zb_nvram_app1_data_size_cb();
  __s = (short *)malloc(__size);
  uVar2 = 0xffffffea;
  if (__s != (short *)0x0) {
    memset(__s,0,__size);
    uVar3 = 2;
    for (iVar6 = 0; iVar6 < (int)(uint)esp_zb_zcl_scenes_table_capacity; iVar6 = iVar6 + 1) {
      __src = (void *)(s_nvram_app1_data + iVar6 * 0xc);
      if ((__src != (void *)0x0) && (*(short *)((int)__src + 2) != -1)) {
        memcpy((void *)((int)__s + uVar3),__src,8);
        uVar3 = uVar3 + 8;
        uVar4 = (uint)*(byte *)((int)__src + 7);
        for (puVar5 = *(undefined1 **)((int)__src + 8); uVar3 = uVar3 & 0xffff,
            puVar5 != (undefined1 *)0x0; puVar5 = *(undefined1 **)(puVar5 + 8)) {
          *(undefined1 *)((int)__s + uVar3) = *puVar5;
          ((undefined1 *)((int)__s + uVar3))[1] = puVar5[1];
          bVar1 = puVar5[2];
          *(byte *)((uVar3 + 2 & 0xffff) + (int)__s) = bVar1;
          uVar3 = uVar3 + 3 & 0xffff;
          memcpy((void *)((int)__s + uVar3),*(void **)(puVar5 + 4),(uint)bVar1);
          uVar3 = uVar3 + (byte)puVar5[2];
          uVar4 = (uVar4 - 3 & 0xffff) - (uint)(byte)puVar5[2] & 0xffff;
        }
        if (uVar4 != 0) {
          uVar2 = 0xffffffff;
          goto _L0;
        }
      }
    }
    *__s = (short)uVar3 + -2;
    uVar2 = zb_nvram_write_data(param_1,param_2,__s,__size);
_L0:
    free(__s);
  }
  return uVar2;
}

