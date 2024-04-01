/*
 * Last changed at upstream commit 3128a1de3a8a176dac99e12775a60287e9d10fd7
 * https://github.com/espressif/esp-zigbee-sdk/commit/3128a1de3a8a176dac99e12775a60287e9d10fd7
 * Upstream date: 2024-04-01 17:59:07 +0800
 * Upstream subject: esp-zigbee-sdk: release/v1.2.2(4a0e02cc)
 * Source: libesp_zb_api_zczr -> esp_zigbee_core.o -> zb_nvram_app1_write_cb
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
  undefined4 *__src;
  byte *pbVar6;
  uint uVar7;
  byte abStack_50 [14];
  undefined2 local_42;
  
  __n = zb_nvram_app1_data_size_cb();
  iVar2 = -(__n + 0xf & 0xfffffff0);
  __src = (undefined4 *)&esp_zb_zcl_scenes_table;
  local_42 = 0;
  memset(abStack_50 + iVar2,0,__n);
  uVar3 = 2;
  do {
    if (*(short *)((int)__src + 2) != -1) {
      memcpy(abStack_50 + uVar3 + iVar2,__src,8);
      uVar3 = uVar3 + 8;
      uVar7 = (uint)*(byte *)((int)__src + 7);
      for (pbVar6 = (byte *)__src[2]; uVar3 = uVar3 & 0xffff, pbVar6 != (byte *)0x0;
          pbVar6 = *(byte **)(pbVar6 + 8)) {
        abStack_50[uVar3 + iVar2] = *pbVar6;
        (abStack_50 + uVar3 + iVar2)[1] = pbVar6[1];
        bVar1 = pbVar6[2];
        abStack_50[(uVar3 + 2 & 0xffff) + iVar2] = bVar1;
        uVar3 = uVar3 + 3 & 0xffff;
        memcpy(abStack_50 + uVar3 + iVar2,*(void **)(pbVar6 + 4),(uint)bVar1);
        uVar3 = uVar3 + pbVar6[2];
        uVar7 = uVar7 + (-3 - (uint)pbVar6[2]) & 0xffff;
      }
      if (uVar7 != 0) {
        return 0xffffffff;
      }
    }
    __src = __src + 3;
    if (__src == &zcl_cli_resp_user_cb) {
      iVar4 = uVar3 - 2;
      abStack_50[iVar2] = (char)iVar4;
      abStack_50[iVar2 + 1] = (byte)((uint)iVar4 >> 8);
      local_42 = (undefined2)iVar4;
      uVar5 = zb_nvram_write_data(param_1,param_2,abStack_50 + iVar2,__n);
      return uVar5;
    }
  } while( true );
}

