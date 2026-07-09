/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> scenes.o -> scene_table_restore
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int scene_table_restore(uint param_1)

{
  byte *pbVar1;
  uint uVar2;
  undefined4 *puVar3;
  void *__dest;
  int iVar4;
  uint uVar5;
  uint __size;
  uint uStack_3c;
  undefined4 uStack_38;
  byte *pbStack_34;
  
  uStack_3c = 0;
  uStack_38 = 0;
  pbStack_34 = (byte *)0x0;
  ds_zcl_scene_info_iterator_init(&uStack_3c);
  do {
    pbVar1 = pbStack_34;
    if ((char)uStack_38 != '\0') {
      iVar4 = 0;
_L0:
      ds_zcl_scene_info_iterator_deinit(&uStack_3c);
      if (iVar4 != 0) {
        scene_table_refresh_stored_scenes(param_1);
      }
      return iVar4;
    }
    if ((pbStack_34 != (byte *)0x0) && (*pbStack_34 == param_1)) {
      iVar4 = scene_table_get_unused_entry(param_1);
      if (iVar4 == 0) {
        iVar4 = 1;
        goto _L0;
      }
      *(undefined2 *)(iVar4 + 2) = *(undefined2 *)(pbVar1 + 1);
      *(byte *)(iVar4 + 4) = pbVar1[3];
      *(undefined2 *)(iVar4 + 6) = *(undefined2 *)(pbVar1 + 0x15);
      *(byte *)(iVar4 + 0x19) = pbVar1[0x17];
      strncpy((char *)(iVar4 + 8),(char *)(pbVar1 + 4),0x11);
      uVar5 = (uStack_3c & 0xffff) - 0x18 & 0xffff;
      uVar2 = 0;
      while ((uVar5 != 0 && (uVar2 < uVar5))) {
        puVar3 = (undefined4 *)calloc(1,0xc);
        if (puVar3 == (undefined4 *)0x0) {
          iVar4 = 1;
          goto _L0;
        }
        *(byte *)(puVar3 + 1) = pbVar1[uVar2 + 0x18];
        *(byte *)((int)puVar3 + 5) = (pbVar1 + uVar2 + 0x18)[1];
        __size = (uint)pbVar1[(uVar2 + 2 & 0xffff) + 0x18];
        *(byte *)((int)puVar3 + 6) = pbVar1[(uVar2 + 2 & 0xffff) + 0x18];
        uVar2 = uVar2 + 3 & 0xffff;
        uVar5 = uVar5 - 3 & 0xffff;
        if (__size != 0) {
          __dest = calloc(1,__size);
          puVar3[2] = __dest;
          if (__dest == (void *)0x0) {
            iVar4 = 1;
            goto _L0;
          }
          memcpy(__dest,pbVar1 + uVar2 + 0x18,__size);
          uVar2 = uVar2 + *(byte *)((int)puVar3 + 6) & 0xffff;
          uVar5 = uVar5 - *(byte *)((int)puVar3 + 6) & 0xffff;
        }
        *puVar3 = *(undefined4 *)(iVar4 + 0x1c);
        *(undefined4 **)(iVar4 + 0x1c) = puVar3;
      }
      scene_table_add_entry(param_1,iVar4,0);
    }
    ds_zcl_scene_info_next(&uStack_3c);
  } while( true );
}

