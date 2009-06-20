/* GStreamer
 * Copyright (C) <1999> Erik Walthinsen <omega@cse.ogi.edu>
 *
 * gstladspa.h: Header for LV2 plugin
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Library General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Library General Public License for more details.
 *
 * You should have received a copy of the GNU Library General Public
 * License along with this library; if not, write to the
 * Free Software Foundation, Inc., 59 Temple Place - Suite 330,
 * Boston, MA 02111-1307, USA.
 */


#ifndef __GST_LV2_H__
#define __GST_LV2_H__


#include <slv2/slv2.h>

#include <gst/gst.h>

#include <gst/signalprocessor/gstsignalprocessor.h>


G_BEGIN_DECLS


typedef struct _lv2_control_info {
  gchar *name;
  gchar *param_name;
  gfloat lowerbound, upperbound;
  gfloat def;
  gboolean lower, upper, samplerate;
  gboolean toggled, logarithmic, integer, writable;
} lv2_control_info;


typedef struct _GstLV2 GstLV2;
typedef struct _GstLV2Class GstLV2Class;


struct _GstLV2 {
  GstSignalProcessor parent;

  SLV2Plugin plugin;
  SLV2Instance instance;

  gboolean activated;
};

struct _GstLV2Port {
  gint      index;
  SLV2Value group;
};

struct _GstLV2Class {
  GstSignalProcessorClass parent_class;

  SLV2Plugin plugin;

  GSList *groups;

  struct _GstLV2Port *audio_in_ports;
  struct _GstLV2Port *audio_out_ports;
  struct _GstLV2Port *control_in_ports;
  struct _GstLV2Port *control_out_ports;
};


G_END_DECLS


#endif /* __GST_LV2_H__ */
