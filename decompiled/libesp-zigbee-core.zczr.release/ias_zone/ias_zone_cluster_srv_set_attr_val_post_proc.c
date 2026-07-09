/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> ias_zone.o -> ias_zone_cluster_srv_set_attr_val_post_proc
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void ias_zone_cluster_srv_set_attr_val_post_proc(int param_1,int param_2,int *param_3)

{
  undefined1 uVar1;
  undefined1 uVar2;
  undefined2 uVar3;
  int iVar4;
  int iVar5;
  undefined2 uStack_36;
  undefined1 auStack_34 [8];
  undefined1 auStack_2c [2];
  undefined1 auStack_2a [18];
  
  if (param_2 == 0x10) {
    if (*param_3 != 0 || param_3[1] != 0) {
      uVar1 = *(undefined1 *)(param_1 + 0x15);
      uVar2 = *(undefined1 *)(param_1 + 0x14);
      uVar3 = *(undefined2 *)(param_1 + 2);
      iVar4 = ias_zone_srv_get_zone_ctx(uVar1);
      if (*(char *)(iVar4 + 2) == '\0') {
        uStack_36 = 0xffff;
        iVar5 = nwk_address_ref_by_short(uVar3,&uStack_36);
        if ((iVar5 == 0) || (iVar5 = nwk_address_update(param_3,uVar3,&uStack_36), iVar5 == 0)) {
          memcpy(auStack_34,param_3,8);
          auStack_2c[0] = 3;
          memcpy(auStack_2a,auStack_34,8);
          nwk_get_extended_address();
          iVar5 = aps_bind_table_add(uVar1,0x500,auStack_2c,uVar2);
          if (iVar5 != 0) {
            log_write(1,"ZCL_IAS_ZONE","Failed to add binding to the cie: %d",iVar5);
          }
          *(undefined1 *)(iVar4 + 2) = 1;
        }
        else {
          log_write(1,"ZCL_IAS_ZONE","Failed to update CIE address: %d",iVar5);
        }
      }
    }
    return;
  }
  return;
}

