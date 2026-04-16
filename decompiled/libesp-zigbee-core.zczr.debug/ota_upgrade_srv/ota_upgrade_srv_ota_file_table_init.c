/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> ota_upgrade_srv.o -> ota_upgrade_srv_ota_file_table_init
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_err_t ota_upgrade_srv_ota_file_table_init(uint8_t ep_id)

{
  size_t __nmemb;
  zcl_attr_desc_t *pzVar1;
  undefined1 *puVar2;
  void *__s;
  ezb_err_t eVar3;
  
  pzVar1 = ota_upgrade_srv_get_attr_desc(ep_id,0xeff1);
  if (pzVar1 == (zcl_attr_desc_t *)0x0) {
    eVar3 = 6;
  }
  else {
    puVar2 = (undefined1 *)calloc(1,8);
    pzVar1->data_p = puVar2;
    if (puVar2 == (undefined1 *)0x0) {
      eVar3 = 1;
    }
    else {
      pzVar1 = ota_upgrade_srv_get_attr_desc(ep_id,0xeff0);
      if (pzVar1 == (zcl_attr_desc_t *)0x0) {
        __nmemb = 0;
      }
      else {
                    /* WARNING: Load size is inaccurate */
        __nmemb = (size_t)*pzVar1->data_p;
      }
      *puVar2 = (char)__nmemb;
      __s = calloc(__nmemb,0x4c);
      *(void **)(puVar2 + 4) = __s;
      if ((__s == (void *)0x0) && (__nmemb != 0)) {
        eVar3 = 1;
      }
      else {
        memset(__s,0,__nmemb * 0x4c);
        eVar3 = 0;
      }
    }
  }
  return eVar3;
}

