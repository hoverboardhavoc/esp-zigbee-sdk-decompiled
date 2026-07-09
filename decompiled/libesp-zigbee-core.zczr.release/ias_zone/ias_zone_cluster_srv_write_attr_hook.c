/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> ias_zone.o -> ias_zone_cluster_srv_write_attr_hook
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void ias_zone_cluster_srv_write_attr_hook(undefined4 param_1,int param_2,ushort *param_3)

{
  ushort uVar1;
  ushort uVar2;
  int iVar3;
  int extraout_a1;
  undefined1 auStack_70 [22];
  ushort uStack_5a;
  undefined1 auStack_58 [11];
  undefined1 uStack_4d;
  undefined1 uStack_4c;
  undefined1 auStack_48 [8];
  ushort uStack_40;
  undefined1 uStack_3e;
  undefined1 uStack_3d;
  ushort uStack_3c;
  undefined1 auStack_38 [36];
  undefined4 uStack_14;
  
  if (param_3 == (ushort *)0x0) {
    param_1 = ias_zone_cluster_srv_write_attr_hook_part_0();
    param_2 = extraout_a1;
  }
  if (param_2 == 2) {
    iVar3 = ias_zone_srv_get_attr_desc(0);
    if (iVar3 != 0) goto _L0;
    do {
      do {
        iVar3 = __assert_func(0,0,0,0);
_L0:
        if (**(char **)(iVar3 + 8) != '\x01') {
          return;
        }
        iVar3 = ias_zone_srv_get_attr_desc(param_1,2);
      } while (iVar3 == 0);
      uVar1 = *param_3;
      param_3 = (ushort *)(uint)uVar1;
      uVar2 = **(ushort **)(iVar3 + 8);
      if ((~(uVar2 & 0x3cf) & (uint)param_3 & 0x3cf) == 0) {
        if ((~(uint)param_3 & (uint)uVar2) == 0) {
          return;
        }
        if ((uVar2 & 0x20) == 0) {
          return;
        }
      }
      memset(auStack_58,0,0x20);
      iVar3 = ias_zone_srv_get_attr_desc(param_1,0x11);
    } while (iVar3 == 0);
    uStack_3e = 0;
    uStack_3d = **(undefined1 **)(iVar3 + 8);
    uStack_3c = 0;
    auStack_58[0] = 0;
    uStack_4d = (undefined1)param_1;
    uStack_40 = uVar1;
    memset(auStack_38,0,0x28);
    iVar3 = zcl_packet_init(auStack_38,0);
    if (iVar3 == 0) {
      memcpy(auStack_70,auStack_58,10);
      iVar3 = zcl_cmd_to_packet(auStack_38,1,0,1,uStack_4c,0,0,0x500);
      if (iVar3 == 0) {
        uStack_5a = uStack_40;
        iVar3 = zmsg_append_bytes(uStack_14,2,&uStack_5a);
        if (iVar3 == 0) {
          uStack_5a = CONCAT11(uStack_5a._1_1_,uStack_3e);
          iVar3 = zmsg_append_bytes(uStack_14,1,&uStack_5a);
          if (iVar3 == 0) {
            uStack_5a = CONCAT11(uStack_5a._1_1_,uStack_3d);
            iVar3 = zmsg_append_bytes(uStack_14,1,&uStack_5a);
            if (iVar3 == 0) {
              uStack_5a = uStack_3c;
              iVar3 = zmsg_append_bytes(uStack_14,2,&uStack_5a);
              if (iVar3 == 0) {
                zcl_packet_send(auStack_38,auStack_48);
                iVar3 = zcl_status_to_err();
                if (iVar3 == 0) {
                  return;
                }
              }
            }
          }
        }
      }
    }
    zcl_packet_free(auStack_38);
  }
  return;
}

