/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> ota_upgrade_srv.o -> ota_upgrade_srv_ota_file_table_init
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 ota_upgrade_srv_ota_file_table_init(undefined4 param_1)

{
  size_t __nmemb;
  int iVar1;
  undefined1 *puVar2;
  void *__s;
  undefined4 uVar3;
  
  iVar1 = ota_upgrade_srv_get_attr_desc(0xeff1);
  if (iVar1 == 0) {
    uVar3 = 6;
  }
  else {
    puVar2 = (undefined1 *)calloc(1,8);
    *(undefined1 **)(iVar1 + 8) = puVar2;
    if (puVar2 == (undefined1 *)0x0) {
      uVar3 = 1;
    }
    else {
      iVar1 = ota_upgrade_srv_get_attr_desc(param_1,0xeff0);
      if (iVar1 == 0) {
        __nmemb = 0;
      }
      else {
        __nmemb = (size_t)**(byte **)(iVar1 + 8);
      }
      *puVar2 = (char)__nmemb;
      __s = calloc(__nmemb,0x4c);
      *(void **)(puVar2 + 4) = __s;
      if ((__s == (void *)0x0) && (__nmemb != 0)) {
        uVar3 = 1;
      }
      else {
        memset(__s,0,__nmemb * 0x4c);
        uVar3 = 0;
      }
    }
  }
  return uVar3;
}

