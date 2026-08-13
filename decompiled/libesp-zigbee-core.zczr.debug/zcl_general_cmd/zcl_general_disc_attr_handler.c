/*
 * Last changed at upstream commit ecca8a8cee0ba565a3b8dbe9d288517b724f31a9
 * https://github.com/espressif/esp-zigbee-sdk/commit/ecca8a8cee0ba565a3b8dbe9d288517b724f31a9
 * Upstream date: 2026-08-13 06:13:24 +0000
 * Upstream subject: change: update esp-zigbee-lib (e4bad48f)
 * Source: libesp-zigbee-core.zczr.debug -> zcl_general_cmd.o -> zcl_general_disc_attr_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void zcl_general_disc_attr_handler(int param_1,int param_2)

{
  ushort uVar1;
  int iVar2;
  ushort *puVar3;
  uint uVar4;
  undefined4 uVar5;
  uint uVar6;
  int unaff_s4;
  ushort uStack_38;
  ushort uStack_36;
  undefined4 uStack_34;
  
  uStack_34 = 0;
  if ((((param_1 == 0) || (unaff_s4 = *(int *)(param_1 + 0x24), unaff_s4 == 0)) || (param_2 == 0))
     || (*(int *)(param_2 + 0x24) == 0)) {
    uVar4 = __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/zcl/zcl_general_cmd.c",0x41d,
                          "zcl_general_disc_attr_handler",
                          "packet && packet->payload && rsp && rsp->payload");
_L0:
    uVar5 = 1;
  }
  else {
    iVar2 = af_get_ep_desc(*(undefined1 *)(param_1 + 0x15));
    if (iVar2 == 0) {
      uVar5 = 0x81;
      goto _L0;
    }
    uVar4 = (uint)*(ushort *)(param_1 + 0x16);
    if ((*(byte *)(param_1 + 0x1a) & 8) == 0) goto _L0;
    uVar5 = 2;
  }
  iVar2 = af_endpoint_get_cluster_desc(uVar4,uVar5);
  if (iVar2 != 0) {
    uVar4 = zmsg_get_length(unaff_s4);
    uStack_36 = 0;
    uVar6 = 0;
_L0:
    do {
      if (uVar4 <= uStack_36) {
        zcl_packet_setup_response(param_2,param_1,0xd);
        return;
      }
      af_read_le16(unaff_s4,&uStack_36,&uStack_34);
      af_read_le8(unaff_s4,&uStack_36,(int)&uStack_34 + 2);
      if (uStack_36 != uVar4) {
        uVar5 = 0x80;
        goto _L0;
      }
      uStack_38 = CONCAT11(uStack_38._1_1_,1);
      zmsg_append_bytes(*(undefined4 *)(param_2 + 0x24),&uStack_38);
      puVar3 = (ushort *)0x0;
      do {
        do {
          puVar3 = (ushort *)zcl_cluster_get_next_attr_desc(iVar2,puVar3);
          if (puVar3 == (ushort *)0x0) goto _L0;
          uVar1 = *puVar3;
        } while ((uint)uVar1 < (uStack_34 & 0xffff));
        if (((*(byte *)((int)puVar3 + 3) & 0x40) == 0) && (uVar1 != 0xfffd)) {
          uStack_38 = uVar1;
          zmsg_append_bytes(*(undefined4 *)(param_2 + 0x24),2,&uStack_38);
          uStack_38 = CONCAT11(uStack_38._1_1_,(char)puVar3[1]);
          zmsg_append_bytes(*(undefined4 *)(param_2 + 0x24),1,&uStack_38);
          uVar6 = uVar6 + 1 & 0xff;
        }
      } while (uVar6 < (uStack_34 >> 0x10 & 0xff));
      uStack_38 = uStack_38 & 0xff00;
      zmsg_write_bytes(*(undefined4 *)(param_2 + 0x24),0,1,&uStack_38);
    } while( true );
  }
  uVar5 = 0xc3;
_L0:
  zcl_packet_setup_default_response(param_2,param_1,uVar5);
  return;
}

