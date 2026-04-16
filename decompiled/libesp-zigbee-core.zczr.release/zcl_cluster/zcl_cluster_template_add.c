/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> zcl_cluster.o -> zcl_cluster_template_add
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

zcl_status_t zcl_cluster_template_add(zcl_cluster_template_t *template)

{
  zcl_cluster_template_t *pzVar1;
  void *__dest;
  int iVar2;
  
  if (template == (zcl_cluster_template_t *)0x0) {
    return 0x87;
  }
  pzVar1 = zcl_cluster_template_find(template->cluster_id,template->cluster_role);
  if (pzVar1 == (zcl_cluster_template_t *)0x0) {
    __dest = calloc(1,0x18);
    if (__dest == (void *)0x0) {
      return 0x89;
    }
    *(int *)((int)__dest + 0x14) = (int)__dest + 0x14;
    memcpy(__dest,template,0x14);
    iVar2 = core_globals_get();
    *(undefined4 *)((int)__dest + 0x14) = *(undefined4 *)(iVar2 + 0xd9c);
    *(int *)(iVar2 + 0xd9c) = (int)__dest + 0x14;
  }
  return '\0';
}

