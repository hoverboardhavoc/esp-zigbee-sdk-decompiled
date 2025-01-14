/*
 * Last changed at upstream commit 5becf8b58fd0c6a13fec507be821364ad0ceba39
 * https://github.com/espressif/esp-zigbee-sdk/commit/5becf8b58fd0c6a13fec507be821364ad0ceba39
 * Upstream date: 2025-01-14 03:03:09 +0000
 * Upstream subject: esp-zigbee-sdk: (acad93d1)
 * Source: libesp_zb_api.zczr -> esp_zigbee_zcl_scenes.o -> zb_nvram_app1_write_cb
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 zb_nvram_app1_write_cb(undefined4 param_1,undefined4 param_2)

{
  byte bVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  size_t __n;
  undefined4 uVar5;
  uint uVar6;
  undefined1 *__src;
  byte *pbVar7;
  byte abStack_40 [14];
  undefined2 local_32;
  
  __n = zb_nvram_app1_data_size_cb();
  iVar2 = -(__n + 0xf & 0xfffffff0);
  __src = &esp_zb_zcl_scenes_table;
  local_32 = 0;
  memset(abStack_40 + iVar2,0,__n);
  uVar3 = 2;
  do {
    if (*(short *)(__src + 2) != -1) {
      memcpy(abStack_40 + uVar3 + iVar2,__src,8);
      uVar3 = uVar3 + 8;
      uVar6 = (uint)(byte)__src[7];
      for (pbVar7 = *(byte **)(__src + 8); uVar3 = uVar3 & 0xffff, pbVar7 != (byte *)0x0;
          pbVar7 = *(byte **)(pbVar7 + 8)) {
        abStack_40[uVar3 + iVar2] = *pbVar7;
        (abStack_40 + uVar3 + iVar2)[1] = pbVar7[1];
        bVar1 = pbVar7[2];
        abStack_40[(uVar3 + 2 & 0xffff) + iVar2] = bVar1;
        uVar3 = uVar3 + 3 & 0xffff;
        memcpy(abStack_40 + uVar3 + iVar2,*(void **)(pbVar7 + 4),(uint)bVar1);
        uVar3 = uVar3 + pbVar7[2];
        uVar6 = (uVar6 - 3 & 0xffff) - (uint)pbVar7[2] & 0xffff;
      }
      if (uVar6 != 0) {
        return 0xffffffff;
      }
    }
    __src = __src + 0xc;
    if (__src == (undefined1 *)0x1159c) {
      iVar4 = uVar3 - 2;
      abStack_40[iVar2] = (char)iVar4;
      abStack_40[iVar2 + 1] = (byte)((uint)iVar4 >> 8);
      local_32 = (undefined2)iVar4;
      uVar5 = zb_nvram_write_data(param_1,param_2,abStack_40 + iVar2,__n);
      return uVar5;
    }
  } while( true );
}

