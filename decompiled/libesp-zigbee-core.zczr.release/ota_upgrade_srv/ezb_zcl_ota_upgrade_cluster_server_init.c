/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> ota_upgrade_srv.o -> ezb_zcl_ota_upgrade_cluster_server_init
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Variable defined which should be unmapped: template */
/* WARNING: Unknown calling convention */

void ezb_zcl_ota_upgrade_cluster_server_init(uint8_t ep_id)

{
  size_t __nmemb;
  undefined3 in_register_00002029;
  int iVar1;
  undefined1 *puVar2;
  void *__s;
  undefined1 auStack_24 [4];
  zcl_cluster_template_t template;
  
  memcpy(auStack_24,&_LANCHOR0,0x14);
  iVar1 = ezb_zcl_get_attr_desc(CONCAT31(in_register_00002029,ep_id),0x19,1,0xeff1,0x131b);
  if (iVar1 != 0) {
    puVar2 = (undefined1 *)calloc(1,8);
    *(undefined1 **)(iVar1 + 8) = puVar2;
    if (puVar2 != (undefined1 *)0x0) {
      iVar1 = ezb_zcl_get_attr_desc(CONCAT31(in_register_00002029,ep_id),0x19,1,0xeff0,0x131b);
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

