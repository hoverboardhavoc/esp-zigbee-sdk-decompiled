/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> ota_upgrade_srv.o -> ezb_zcl_ota_upgrade_cluster_server_init
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void ezb_zcl_ota_upgrade_cluster_server_init(undefined4 param_1)

{
  size_t __nmemb;
  int iVar1;
  undefined1 *puVar2;
  void *__s;
  undefined1 auStack_24 [20];
  
  memcpy(auStack_24,&_LANCHOR0,0x14);
  iVar1 = ezb_zcl_get_attr_desc(param_1,0x19,1,0xeff1,0x131b);
  if (iVar1 != 0) {
    puVar2 = (undefined1 *)calloc(1,8);
    *(undefined1 **)(iVar1 + 8) = puVar2;
    if (puVar2 != (undefined1 *)0x0) {
      iVar1 = ezb_zcl_get_attr_desc(param_1,0x19,1,0xeff0,0x131b);
      __nmemb = 0;
      if (iVar1 != 0) {
        __nmemb = (size_t)**(byte **)(iVar1 + 8);
      }
      *puVar2 = (char)__nmemb;
      __s = calloc(__nmemb,0x4c);
      *(void **)(puVar2 + 4) = __s;
      if ((__s != (void *)0x0) || (__nmemb == 0)) {
        memset(__s,0,__nmemb * 0x4c);
        iVar1 = zcl_cluster_template_add(auStack_24);
        if (iVar1 == 0) {
          return;
        }
      }
    }
  }
  __assert_func(0,0,0,0);
  return;
}

